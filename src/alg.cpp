// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; j > i; --j) {
          if (arr[i] + arr[j] == value)
            ++counter;
        }
    }
    return counter;
}

int checkByBinsearch(int *arr, int left, int right, int val) {
    int count = 0;
    while (right - left > 1) {
        int center = (left + right) / 2;
        if (arr[center] == val) {
            ++count;
            int step = center + 1;
            while (arr[step] == val && step < right) {
                ++count;
                ++step;
            }
            step = center - 1;
            while (arr[step] == val && step > left) {
                ++count;
                --step;
            }
            break;
        }
        if (arr[center] < val) {
            left = center;
        }
        if (arr[center] > val) {
            right = center;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len - 1; ++i) {
        int pairValue = value - arr[i];
        counter += checkByBinsearch(arr, i, len, pairValue);
    }
    return counter;
}
