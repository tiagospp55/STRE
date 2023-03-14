
#include <stdio.h>
#include <stdlib.h>
#include "MyFifo.h"




/**
 *
 * \brief init the module
 * 
 * \param[in] fifo struct fifo
 * \param[in] size size of FIFO
*/
void MyFIFOInit(struct MyFIFO *fifo,int size){   
    fifo->data = (int*) malloc(size * sizeof(int));
    fifo->head = 0;
    fifo->tail = 0;
    fifo->cnt = 0;
    fifo->size = size;
}


/**
 *
 * \brief adds an element to the FIFO
 * 
 * \param[in] fifo struct fifo
 * \param[in] value element to add in the FIFO
 * \param[out] return return 0 it the function do is job or return fifo_full if the FiFO is full 
*/
int MyFIFOInsert(struct MyFIFO *fifo,int value){
    
    if(fifo->cnt == fifo->size) {
        printf("%d não foi inserido (tamanho máximo atingido)\n", value);
        return fifo_Full; 
    }
    fifo->data[fifo->tail] = value;
    if(fifo->tail == fifo->size) {
        fifo->tail = 0;
        fifo->cnt++;
        printf("Inserir %d\n", value);
        return 0;
    }
    fifo->tail++;
    fifo->cnt++;
    printf("Inserir %d\n", value);
    return 0;
}


/**
 *
 * \brief Removes an element from the FIFO
 * 
 * \param[in] fifo struct fifo
 * \param[out] return return 0 it the function do is job or return fifo_Empty if the FiFO is empty 
*/
int MyFIFORemove(struct MyFIFO *fifo){
    printf("Remove %d\n", fifo->data[fifo->head]);
    if(fifo->cnt == 0) return fifo_Empty;
    if(fifo->head == fifo->size){
        fifo->head = 0;
    } 
    else{
        fifo->head++;
        fifo->cnt--;
    }
    
    return 0;

}
/**
 *
 * \brief Return the oldest element on the FIFO,but does not remove
 * 
 * \param[in] fifo struct fifo
 * \param[out] return return the oldest element
 * 
*/


int MyFIFOPeep(struct MyFIFO *fifo){
    return fifo->data[fifo->head];
}

/**
 *
 * \brief Returns the number of elements of the FIFO
 * 
 * \param[in] fifo struct fifo
 * \param[out] return return the number of elements of the FIFO
 * 
*/
int MyFIFOSize(struct MyFIFO *fifo){
    return fifo->cnt;
}


/**
 *
 * \brief Destroy the FIFO
 * 
 * \param[in] fifo struct fifo
*/

void MyFIFODestroy(struct MyFIFO *fifo){
    free(fifo->data);
    free(fifo);
}


/**
 * \brief write fifo elements in order 
 * 
 * \param[in] fifo struct fifo
 * 
*/
void MyFIFOPrint(struct MyFIFO *fifo)
{
    if((fifo->cnt + fifo->head) <= fifo->size){
        for(int i = fifo->head; i < (fifo->head + fifo->cnt); i++){
            printf("%d ", fifo->data[i]);
        }
        printf("\n");
    }else if(fifo->cnt + fifo->head > fifo->size){
        
        int res = 0;
        for(int i = fifo->head; i < (fifo->head + fifo->cnt)-1; i++){
            printf("%d ", fifo->data[i]);
            res++;
        }
        for(int i = 0; i <= (fifo->cnt - res); i++){ 
            printf("%d ", fifo->data[i]);
        }
    }

}

