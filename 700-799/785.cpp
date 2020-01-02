#include <cstdio>
#include <iostream>

using namespace std;

int data[100000+5];
int flag;

int partition(int low, int high) {
    int mid = low + (high - low) / 2;
    swap(data[mid], data[low]);
    int pivot = data[low];
    flag = true;
    for(int i = low + 1; i <= high; i ++)
        if(data[i] != data[low]) {
            flag = false;
            break;
        }
    if(flag)
        return low;
    while(low < high) {
        while(low < high && data[high] >= pivot)
            high --;
        data[low] = data[high];
        while(low < high && data[low] <= pivot)
            low ++;
        data[high] = data[low];
    }
    data[low] = pivot;
    return low;
}
void quick_sort(int low, int high) {
    if(low < high) {
        int pivot = partition(low, high);
        if(flag)
            return ;
        quick_sort(low, pivot-1);
        quick_sort(pivot+1, high);
    }
}

int main() {
    int nums = 0;
    while(cin >> nums) {
        for(int i = 0; i < nums; i ++)
            cin >> data[i];
        quick_sort(0, nums-1);
        for(int i = 0; i < nums-1; i ++)
            cout << data[i] << " ";
        cout << data[nums-1] << endl;
    }

}