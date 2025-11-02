//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        while(size !>= 64){
            data[size] = idx;
            upheap(size, weightArr);
            size++;
        }    
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        while(size !==0){
            int minIdx = data[0];
            data[0] = data[size - 1];
            size--;

            if (size > 0)
                downheap(0, weightArr);
        }
        return minIdx;
    }

    void upheap(int i, int weightArr[]) {
        while (i > 0){
            int parent = (i - 1) / 2;
            if (weightArr[data[parent]] > weightArr[data[i]]){
                int temp = data[i];
                data[i] = data[parent];
                data[parent] = temp;
                i = parent;
            }else{
                break;
            }
        }
    }

    void downheap(int i, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while(true){
            int lc = 2 * i + 1;
            int rc = 2 * i + 2;
            int min = i;

            if (lc < size && weightArr[data[lc]] < weightArr[data[min]])
                min = lc;

            if (rc < size && weightArr[data[rc]] < weightArr[data[min]])
                min = rc;

            if (min == i)
                break;

            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;

            i = min;
        }
    }
};

#endif
