#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool determin(int max_lange, int count, int belegung, int *arr, int *ziel)
{
    if (max_lange == 0)
    {
        return true;
    }
    for (int i = 0; i < count; i++)
    {
            ziel[belegung] = arr[i];
            arr[i] = 0;
        if(ziel[belegung]!=0){   
        if ((max_lange - ziel[belegung]>=0) && determin(max_lange-ziel[belegung], count, belegung+1, arr, ziel))
        {
                return true;
        }
        }
        arr[i] = ziel[belegung];
    }
    ziel[belegung] = 0;
    return false;
}

int main()
{
    int stucke[] = {9, 8, 4, 4, 7};
    int *ziel = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
    {
        ziel[i] = 0;
    }
    printf("\n\nhi!"); 

    if(determin(20, 5, 0, stucke, ziel)){
        printf("\n\nerfolgreich :)");
    }
 
    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", ziel[i]);
    }
    return 0;
}