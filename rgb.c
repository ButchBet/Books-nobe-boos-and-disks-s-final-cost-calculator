#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct where are saved the rgb values */
typedef struct RGB{
    int r;
    int g;
    int b;
}Rgb;

/* Method to set the values inside the struct */
void rgb_set(Rgb *rgb, int r, int g, int b){
    if(r + g + b <= 255*3 && (r >= 0 && g >= 0 && b >= 0)){
        rgb->r = r;
        rgb->g = g;
        rgb->b = b;
    }
}

/* Method to invert the values of the struct */
void rgb_invert(Rgb *rgb){
    rgb_set(rgb, 255 - rgb->r, 255 - rgb->g, 255 - rgb->b);
}

/* Function to return the printing of the reverted values and the hex representation */
char *rgb_str(Rgb *rgb){
    char *str = malloc(sizeof(char) * 64);
    sprintf(
        str, "RGB: (%i, %i, %i),\nHEX: 0x%02x%02x%02x.\n\n",
         rgb->r, rgb->g, rgb->b, rgb->r, rgb->g, rgb->b
         );
    return str;
}

/* Function that get the file to invert rgb */
//Rgb  *rgb_get_inverted_color(char *file, int limit){
void rgb_get_inverted_color(char *file, int limit){
    /* Creating of the array type Rgb */
    Rgb *inverted = malloc(sizeof(Rgb) * limit);

    FILE *fp;

    /* Check correct file opened */
    if((fp = fopen(file, "r")) == NULL){
        fprintf(stderr, "Error opening the file.\n");
        exit(-1);
    }

    /* Create and array of char and allocate space to can save each line */
    int size_line = 16;
    char *line = malloc(sizeof(char) * size_line);

    /* Write inside the line each file line */
    int i = 0;
    while(fgets(line, size_line, fp)){
       if(i >= limit){
           fprintf(stderr, "Error, the life has so much lines.");
           exit(-1);
       }

       /* Split the readed lines */
       int values[4];
       char *split = malloc(sizeof(char) * size_line);
       split = strdup(line);

       char *token = strtok(split, " ");

       int j = 0;
       while(token != NULL){
           if(j == 0){
                values[j] = atoi(token);
           }else{
                token = strtok(NULL, " ");
                values[j] = atoi(token);
           }
            j++;
        }

        free(split);

        /* Inicialize and invert each Rgb value */
        rgb_set(&inverted[i], values[0], values[1], values[2]);
        rgb_invert(&inverted[i]);

        /* Show the inverted line */
        printf(rgb_str(&inverted[i]));

        i++;
        }

    fclose(fp);
}

int main(int argc, char **argv){
    /* Check that only enter 2 elements */
    if(argc != 2){
        fprintf(stderr, "USE: rgb file.\n");
        exit(EOF);
    }

    int limit = 4;
    rgb_get_inverted_color(argv[1], limit);
    return 0;
}