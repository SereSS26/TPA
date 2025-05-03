#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *f1(int n,char *s1,char *s2)
{
    if(n==0)
        return s1;
    else
    {   
        char *aux=NULL;
        aux=(char*)malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
        if(aux==NULL)
        {
            perror("eroare\n");
            exit(-1);
        }
        strcpy(aux,s1);
        strcat(aux,s2);
        strcpy(s1,s2);
        strcpy(s2,aux);
        free(aux);
        return f1(n-1,s1,s2);
    }
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("1.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("1.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    char s1[200],s2[200];
    int n=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%199s",s1);
    fscanf(fis,"%199s",s2);
    fprintf(gis,"%s\n",f1(n,s1,s2));
    fclose(fis);
    fclose(gis);

    return 0;
}