#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
uint8_t A[3];

void ClacEveryBit(uint8_t num) {
    A[2] = num /100;
    A[1] = num % 100 / 10;
    A[0] = num % 100 % 10;
}

bool IsIn(uint8_t x, uint8_t y, uint8_t z) {
    bool ret = true;
    if (A[0] == A[1] || A[0] == A[2] || A[1] == A[2])
    { // 排除三个数字有重复的情况
        ret = false;
    }
    // 排除有效位有 0 的情况
    if(A[2] != 0 && (A[1] == 0 || A[0] == 0)) { // 有效位为 A[0] A[1] A[2]
        ret = false;
    }
    if (A[2] == 0 && A[1] != 0 && A[0] == 0)
    { // 有效位为 A[1] 和 A[0]
        ret = false;
    }
    if(A[2] == 0 && A[1] == 0 && A[0] == 0) { // 有效为为 A[0]
        ret =false;
    }
    
    for(int i = 0; i < 3; i++) {
        
        if(A[i] == 5) A[i] = 2;
        if(A[i] == 9) A[i] = 6;
        if(A[i] != x && A[i] != y && A[i] != z) {
            ret = false;
            break;
        }
        if(A[i] == 0) break;
    }
    return ret;
}

uint8_t GiveNthNum(uint8_t x, uint8_t y, uint8_t z, uint8_t seq) {
    uint8_t seq_match = 0;
    uint8_t ret = 0;
    uint8_t SAVE_MAX[3] = {0};
    for(int i = 0; i < 999; i++) {
        ClacEveryBit(i);
        if(IsIn(x, y, z)) {
            seq_match ++;
            SAVE_MAX[0] = A[0]; SAVE_MAX[1] = A[1]; SAVE_MAX[2] = A[2];
            if(seq == seq_match) {
                ret = A[2] * 100 + A[1] * 10 + A[0];
                break;
            }
        }
    }
    return  SAVE_MAX[0] + SAVE_MAX[1] * 10 + SAVE_MAX[2] * 100;

}



int main() {
    uint8_t input_num[4] = {0};
    uint8_t DestNum;
    if(scanf("%d, %d, %d", &input_num[0], &input_num[1], &input_num[2], &input_num[3]) < 4) {
        return -1;
    }
    for(int i = 0; i < 3; i++) {
        if(input_num[i] > 9 || input_num[i] <= 0) return -1;

        if(input_num[i] == 5) input_num[i] = 2;
        if(input_num[i] == 9) input_num[i] = 6;
    }
    DestNum = GiveNthNum(input_num[0], input_num[1], input_num[2], input_num[3]);
    printf("%d\n", DestNum);
}