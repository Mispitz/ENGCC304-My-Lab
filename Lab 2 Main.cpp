#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char drinkNames[4][50] = {"โค้ก", "น้ำเขียว", "อเมริกาโน่", "ลาเต้ หวานเจี๊ยบ"};
    double drinkPrices[4] = {10.0, 12.0, 30.0, 35.0};
    int drinkQuantities[4] = {10, 15, 10, 12}; // จำนวนสินค้าในสต็อกเริ่มต้น

    char snackNames[3][50] = {"เมล็ดทานตะวัน", "ถั่วแปบ", "จิ้นส้มหมก"};
    double snackPrices[3] = {13.0, 20.0, 15.0};
    int snackQuantities[3] = {20, 10, 5}; // จำนวนสินค้าในสต็อกเริ่มต้น

    int mainChoice, subChoice, choiceNum;
    int qty, i;
    double total = 0.0, paid, change;

    while (1) {
        printf("\n=== ระบบจัดการและจำหน่ายสินค้า ===\n");
        printf("1. โหมดลูกค้า (ซื้อสินค้า)\n");
        printf("2. โหมดผู้ดูแลระบบ (จัดการสต็อก)\n");
        printf("3. ออกจากระบบ\n");
        printf("------------------------------------\n");
        printf("เลือกโหมดการทำงาน: ");
        if (scanf("%d", &mainChoice) != 1) {
            printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (mainChoice == 1) { // โหมดลูกค้า
            total = 0.0;

            do {
                printf("\n--- เมนูสินค้า ---\n");
                printf("1. เครื่องดื่ม\n");
                printf("2. ขนม\n");
                printf("0. จบการซื้อและชำระเงิน\n");
                printf("ยอดรวม: %.2f บาท\n", total);
                printf("เลือกประเภทสินค้า: ");
                if (scanf("%d", &subChoice) != 1) {
                    printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');

                if (subChoice == 1) { // เลือกเครื่องดื่ม
                    printf("\n--- เครื่องดื่มที่มี ---\n");
                    for (i = 0; i < 4; i++) {
                        printf("%d. %s (เหลือ %d ชิ้น) - %.2f บาท\n", i + 1, drinkNames[i], drinkQuantities[i], drinkPrices[i]);
                    }
                    printf("เลือกสินค้า: ");
                    if (scanf("%d", &choiceNum) != 1) {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');

                    if (choiceNum >= 1 && choiceNum <= 4) {
                        printf("จำนวนที่ต้องการ: ");
                        if (scanf("%d", &qty) != 1) {
                            printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                            while (getchar() != '\n');
                            continue;
                        }
                        while (getchar() != '\n');
                        if (qty > 0 && qty <= drinkQuantities[choiceNum - 1]) {
                            drinkQuantities[choiceNum - 1] -= qty;
                            total += drinkPrices[choiceNum - 1] * qty;
                            printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", drinkNames[choiceNum - 1], qty);
                        } else {
                            printf("จำนวนไม่ถูกต้องหรือสินค้าไม่พอ\n");
                        }
                    } else {
                        printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                    }
                } else if (subChoice == 2) { // เลือกขนม
                    printf("\n--- ขนมที่มี ---\n");
                    for (i = 0; i < 3; i++) {
                        printf("%d. %s (เหลือ %d ชิ้น) - %.2f บาท\n", i + 1, snackNames[i], snackQuantities[i], snackPrices[i]);
                    }
                    printf("เลือกสินค้า: ");
                    if (scanf("%d", &choiceNum) != 1) {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');

                    if (choiceNum >= 1 && choiceNum <= 3) {
                        printf("จำนวนที่ต้องการ: ");
                        if (scanf("%d", &qty) != 1) {
                            printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                            while (getchar() != '\n');
                            continue;
                        }
                        while (getchar() != '\n');
                        if (qty > 0 && qty <= snackQuantities[choiceNum - 1]) {
                            snackQuantities[choiceNum - 1] -= qty;
                            total += snackPrices[choiceNum - 1] * qty;
                            printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", snackNames[choiceNum - 1], qty);
                        } else {
                            printf("จำนวนไม่ถูกต้องหรือสินค้าไม่พอ\n");
                        }
                    } else {
                        printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                    }
                } else if (subChoice != 0) {
                    printf("ตัวเลือกประเภทสินค้าไม่ถูกต้อง\n");
                }
            } while (subChoice != 0);

            if (total > 0) {
                printf("\n--- ชำระเงิน ---\n");
                printf("ยอดรวมทั้งหมด: %.2f บาท\n", total);
                printf("กรุณาใส่เงิน: ");
                if (scanf("%lf", &paid) != 1) {
                    printf("กรุณาใส่จำนวนเงินที่ถูกต้อง\n");
                    while (getchar() != '\n');
                }

                if (paid < total) {
                    printf("เงินไม่พอ! รายการถูกยกเลิก\n");
                    // คืนสินค้า
                    // (ในโค้ดนี้ไม่มีระบบคืนสินค้าอัตโนมัติ)
                } else {
                    change = paid - total;
                    printf("การชำระเงินสำเร็จ\n");
                    printf("เงินทอน: %.2f บาท\n", change);

                    int int_change = (int)(change + 0.5); // ปัดเศษเงินทอนให้เป็นจำนวนเต็ม
                    int count;

                    if (int_change >= 1000) {
                        count = int_change / 1000;
                        printf("ธนบัตร 1000 บาท = %d ใบ\n", count);
                        int_change %= 1000;
                    }
                    if (int_change >= 500) {
                        count = int_change / 500;
                        printf("ธนบัตร 500 บาท = %d ใบ\n", count);
                        int_change %= 500;
                    }
                    if (int_change >= 100) {
                        count = int_change / 100;
                        printf("ธนบัตร 100 บาท = %d ใบ\n", count);
                        int_change %= 100;
                    }
                    if (int_change >= 50) {
                        count = int_change / 50;
                        printf("ธนบัตร 50 บาท = %d ใบ\n", count);
                        int_change %= 50;
                    }
                    if (int_change >= 20) {
                        count = int_change / 20;
                        printf("ธนบัตร 20 บาท = %d ใบ\n", count);
                        int_change %= 20;
                    }
                    if (int_change >= 10) {
                        count = int_change / 10;
                        printf("เหรียญ 10 บาท = %d เหรียญ\n", count);
                        int_change %= 10;
                    }
                    if (int_change >= 5) {
                        count = int_change / 5;
                        printf("เหรียญ 5 บาท = %d เหรียญ\n", count);
                        int_change %= 5;
                    }
                    if (int_change >= 2) {
                        count = int_change / 2;
                        printf("เหรียญ 2 บาท = %d เหรียญ\n", count);
                        int_change %= 2;
                    }
                    if (int_change >= 1) {
                        count = int_change / 1;
                        printf("เหรียญ 1 บาท = %d เหรียญ\n", count);
                        int_change %= 1;
                    }

                    printf("สินค้าถูกจัดส่งแล้ว\n");
                }
            }
            printf("\nขอบคุณที่ใช้บริการ!\n");

        } else if (mainChoice == 2) { // โหมดผู้ดูแลระบบ
            printf("\n--- โหมดผู้ดูแลระบบ ---\n");
            printf("1. เติมสต็อกเครื่องดื่ม\n");
            printf("2. เติมสต็อกขนม\n");
            printf("3. ดูสต็อกเครื่องดื่ม\n");
            printf("4. ดูสต็อกขนม\n");
            printf("5. กลับสู่เมนูหลัก\n");
            printf("เลือกเมนู: ");
            if (scanf("%d", &subChoice) != 1) {
                printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');

            if (subChoice == 1) { // เติมสต็อกเครื่องดื่ม
                printf("\n--- เติมสต็อกเครื่องดื่ม ---\n");
                for (i = 0; i < 4; i++) {
                    printf("%d. %s (เหลือ %d ชิ้น)\n", i + 1, drinkNames[i], drinkQuantities[i]);
                }
                printf("เลือกสินค้าที่จะเติมสต็อก: ");
                if (scanf("%d", &choiceNum) != 1) {
                    printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (choiceNum >= 1 && choiceNum <= 4) {
                    printf("จำนวนที่ต้องการเพิ่ม: ");
                    if (scanf("%d", &qty) != 1) {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if (qty > 0) {
                        drinkQuantities[choiceNum - 1] += qty;
                        printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", drinkNames[choiceNum - 1], qty);
                    } else {
                        printf("จำนวนที่เพิ่มไม่ถูกต้อง\n");
                    }
                } else {
                    printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                }
            } else if (subChoice == 2) { // เติมสต็อกขนม
                printf("\n--- เติมสต็อกขนม ---\n");
                for (i = 0; i < 3; i++) {
                    printf("%d. %s (เหลือ %d ชิ้น)\n", i + 1, snackNames[i], snackQuantities[i]);
                }
                printf("เลือกสินค้าที่จะเติมสต็อก: ");
                if (scanf("%d", &choiceNum) != 1) {
                    printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (choiceNum >= 1 && choiceNum <= 3) {
                    printf("จำนวนที่ต้องการเพิ่ม: ");
                    if (scanf("%d", &qty) != 1) {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if (qty > 0) {
                        snackQuantities[choiceNum - 1] += qty;
                        printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", snackNames[choiceNum - 1], qty);
                    } else {
                        printf("จำนวนที่เพิ่มไม่ถูกต้อง\n");
                    }
                } else {
                    printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                }
            } else if (subChoice == 3) {
                printf("\n--- สต็อกเครื่องดื่ม ---\n");
                for (i = 0; i < 4; i++) {
                    printf("%d. %s (เหลือ %d ชิ้น) - %.2f บาท\n", i + 1, drinkNames[i], drinkQuantities[i], drinkPrices[i]);
                }
            } else if (subChoice == 4) {
                printf("\n--- สต็อกขนม ---\n");
                for (i = 0; i < 3; i++) {
                    printf("%d. %s (เหลือ %d ชิ้น) - %.2f บาท\n", i + 1, snackNames[i], snackQuantities[i], snackPrices[i]);
                }
            } else if (subChoice != 5) {
                printf("ตัวเลือกไม่ถูกต้อง\n");
            }

        } else if (mainChoice == 3) { // ออกจากระบบ
            printf("ออกจากโปรแกรม\n");
            break;
        } else {
            printf("ตัวเลือกไม่ถูกต้อง กรุณาเลือกอีกครั้ง\n");
        }
    }

    return 0;
}