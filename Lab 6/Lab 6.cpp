#include <stdio.h> 

int main() {
    int N; 

    for (;;) { 
        printf("กรุณากรอกตัวเลขจำนวนเต็ม (N): "); 

        if (scanf("%d", &N) == 1) {
            for (; getchar() != '\n'; );
            break; 
        } else {
            printf("ข้อมูลที่ป้อนไม่ถูกต้อง กรุณาป้อนตัวเลขจำนวนเต็มเท่านั้น\n");
            for (; getchar() != '\n'; );
        }
    }

    if (N % 2 != 0) { 
        printf("คุณกรอกเลขคี่ (%d) โปรแกรมจะแสดงเลขคี่ตั้งแต่ 1 ถึง %d:\n", N, N);
        for (int i = 1; i <= N; i += 2) {
            printf("%d\n", i); 
        }
    } else { 
        printf("คุณกรอกเลขคู่ (%d) โปรแกรมจะแสดงเลขคู่ตั้งแต่ %d ถึง 0:\n", N, N);
        for (int i = N; i >= 0; i -= 2) {
            printf("%d\n", i); 
        }
    }

    return 0; 
}