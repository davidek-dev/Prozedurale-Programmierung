//
//  sort.c
//  blatt08
//
//  Created by Marvin Heydorn on 09.01.21.
//

#include "sort.h"

void bubbleSort(int *array,int length){
    
    int temp;
    
    for(int i = 0; i < length; i++ ){
        for(int j = 0; j < length; j++){
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
           
        }
    }
}

void mergeSort(int *array, int length){
    
    if(length > 1){
     
            int left[length / 2];
            int right[(length + 1) / 2];
            int i;
            for(i = 0; i < length / 2; ++i)
                left[i] = array[i];
            for(i = length / 2; i < length; i++)
                right[i - length / 2] = array[i];
     
            mergeSort(left,length / 2);
            mergeSort(right,(length + 1) / 2);
     
            int *pos1 = &left[0];
            int *pos2 = &right[0];
            for(i = 0; i < length; i++){
                if(*pos1 <= *pos2){
                   array[i] = *pos1;
                    if (pos1 != &right[(length + 1) / 2 - 1]) {
                        if(pos1 == &left[length / 2 - 1]){
                            pos1 = &right[(length + 1) / 2 - 1];
                        }
                        else{
                            ++pos1;
                        }
                    }
                }
                else{
                    array[i] = *pos2;
                    if(pos2 == &right[(length + 1) / 2 - 1]){
                        pos2 = &left[length / 2 - 1];
                    }
                    else{
                        ++pos2;
                    }
                }
            }
        }
    
}

