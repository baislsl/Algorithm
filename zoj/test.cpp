//
//void swap(int *a, int i, int j){
//    int tmp = a[i];
//    a[i] = a[j];
//    a[j] = tmp;
//}
//
//void qsort(int a[], int size){
//    push(pair<0, size>);
//    while((auto p = pop()) != nullptr){
//        begin = p.first;
//        end = p.second;
//        int key = a[begin];
//        int left = begin, right = end - 1;
//        while(left < right){
//            while(left < right && a[right] >= key) right--;
//            a[left] = a[right];
//            while(left < right && a[left] <= key ) left++;
//            a[right] = a[left];
//        }
//        a[left] = key;
//        if(begin < left - 1)
//            push(pair<begin, left>);
//        if(left + 1 < end - 1)
//            push(pair<left + 1,end>);
//    }
//
//
//
//}