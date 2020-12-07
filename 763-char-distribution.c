#include <stdlib.h>
#include <string.h>
#if 0
int cmp(const void * a, const void * b) {
    if(*(int*)a < *(int*)b) {
        return -1;
    } else if(*(int*)a == *(int*)b) {
        return 0;
    } else {
        return 1;
    }
}
int* partitionLabels(char * S, int* returnSize){
    int min[26];
    int max[26];
    int element[26];
    int * res = (int *) malloc(26 * sizeof(int));
    

    for(int i = 0; i < 26; ++i) {
        min[i] = 10000000;
        max[i] = -1;
        element[i] = i;
    }

    for(int i = 0; i < strlen(S); ++i) {
        if(i > max[S[i] - 'a']) {
            max[S[i] - 'a'] = i;
        }
        if(i < min[S[i] - 'a']) {
            min[S[i] - 'a'] = i;
        }
    }

    for(int i = 0; i < 26; ++i) {
        for(int j = i + 1; j < 26; ++j) {
		// 这里判断条件有误，因为当前的字母可能是空集，即min[j] == 1000000, max[j] == -1
            if(element[i] != element[j] && !(max[i] < min[j] || min[i] > max[j])) {
                int tmp_min = min[i] < min[j] ? min[i] : min[j];
                int tmp_max = max[i] > max[j] ? max[i] : max[j];
                min[i] = min[j] = tmp_min;
                max[i] = max[j] = tmp_max;
                element[j] = element[i];
            }
        }
    }

    qsort(max, 26, sizeof(int), cmp);
    *returnSize = 0;
    for(int i = 0; i < 26; ++i) {

        if(max[i] != -1 && (i == 0 || max[i] != max[i - 1])) {
            int dur;
            if(i == 0) {
                dur = max[i] + 1;
            } else if(max[i - 1] < 0) {
                dur = max[i] + 1;
            } else {
                dur = max[i] - max[i - 1];
            }

            res[(*returnSize)++] = dur;
        }
    }
    
    return res;
}
#endif

// 使用贪心策略
int* partitionLabels(char * S, int* returnSize){
    int max[26];
    int *res = malloc(sizeof(int) * 26);
    int start, end;
    *returnSize = 0;

    // 求出每一个字母最后出现的位置
    for(int i = 0; i < strlen(S); ++i) {
        max[S[i] - 'a'] = i; 
    }

    // 使用双指针
    start = end = 0;
    for(int i = 0; i < strlen(S); ++i) {
    	// 每次更新当前段，因为当前段总应该不在当前字母最后出现位置之前
        end = end > max[S[i] - 'a'] ? end : max[S[i] - 'a'];
        if(i == end) {
            res[(*returnSize)++] = end - start + 1;
            start = end + 1;
        }
    }
    return res;
}

