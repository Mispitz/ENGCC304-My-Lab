#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // เครื่องดื่ม
    char drinkName1[50] = "โค้ก";
    char drinkName2[50] = "น้ำเขียว";
    char drinkName3[50] = "อเมริกาโน่";
    char drinkName4[50] = "ลาเต้ หวานเจี๊ยบ";
    double drinkPrice1 = 10.0, drinkPrice2 = 12.0, drinkPrice3 = 30.0, drinkPrice4 = 35.0;
    int drinkQty1 = 10, drinkQty2 = 10, drinkQty3 = 10, drinkQty4 = 10;

    // ขนม
    char snackName1[50] = "เมล็ดทานตะวัน";
    char snackName2[50] = "ถั่วแปบ";
    char snackName3[50] = "จิ้นส้มหมก";
    double snackPrice1 = 13.0, snackPrice2 = 20.0, snackPrice3 = 15.0;
    int snackQty1 = 10, snackQty2 = 10, snackQty3 = 10;

    // สต็อกแบงค์และเหรียญ
    int stock1000 = 1, stock500 = 1, stock100 = 3, stock50 = 8, stock20 = 15;
    int stock10 = 200, stock5 = 500, stock1 = 1000;

    int mainChoice, subChoice, choiceNum;
    int qty;
    double total = 0.0, paid, change;

    while (1)
    {
        printf("\n=== ระบบจัดการและจำหน่ายสินค้า ===\n");
        printf("1. Customer (ซื้อสินค้า)\n");
        printf("2. Admin (จัดการสต็อก)\n");
        printf("3. Exit\n");
        printf("--------------------------------\n");
        printf("เลือกโหมดการทำงาน: ");
        if (scanf("%d", &mainChoice) != 1)
        {
            printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (mainChoice == 1)
        {
            total = 0.0;

            do
            {
                printf("\n------ เมนูสินค้า ------\n");
                printf("1. เครื่องดื่ม\n");
                printf("2. ขนม\n");
                printf("0. จบการซื้อและชำระเงิน\n");
                printf("_____________________\n");
                printf("ยอดรวม: %.2f บาท\n", total);
                printf("เลือกประเภทสินค้า: ");
                if (scanf("%d", &subChoice) != 1)
                {
                    printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                while (getchar() != '\n')
                    ;

                if (subChoice == 1)
                {
                    printf("\n------ เครื่องดื่มที่มี ------\n");
                    printf("1. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName1, drinkQty1, drinkPrice1);
                    printf("2. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName2, drinkQty2, drinkPrice2);
                    printf("3. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName3, drinkQty3, drinkPrice3);
                    printf("4. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName4, drinkQty4, drinkPrice4);
                    printf("เลือกสินค้า: ");
                    if (scanf("%d", &choiceNum) != 1)
                    {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n')
                            ;
                        continue;
                    }
                    while (getchar() != '\n')
                        ;

                    if (choiceNum >= 1 && choiceNum <= 4)
                    {
                        printf("จำนวนที่ต้องการ: ");
                        if (scanf("%d", &qty) != 1)
                        {
                            printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                            while (getchar() != '\n')
                                ;
                            continue;
                        }
                        while (getchar() != '\n')
                            ;
                        if (qty > 0)
                        {
                            if (choiceNum == 1 && qty <= drinkQty1)
                            {
                                drinkQty1 -= qty;
                                total += drinkPrice1 * qty;
                                printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", drinkName1, qty);
                            }
                            else if (choiceNum == 2 && qty <= drinkQty2)
                            {
                                drinkQty2 -= qty;
                                total += drinkPrice2 * qty;
                                printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", drinkName2, qty);
                            }
                            else if (choiceNum == 3 && qty <= drinkQty3)
                            {
                                drinkQty3 -= qty;
                                total += drinkPrice3 * qty;
                                printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", drinkName3, qty);
                            }
                            else if (choiceNum == 4 && qty <= drinkQty4)
                            {
                                drinkQty4 -= qty;
                                total += drinkPrice4 * qty;
                                printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", drinkName4, qty);
                            }
                            else
                            {
                                printf("จำนวนไม่ถูกต้องหรือสินค้าไม่พอ\n");
                            }
                        }
                        else
                        {
                            printf("จำนวนไม่ถูกต้องหรือสินค้าไม่พอ\n");
                        }
                    }
                    else
                    {
                        printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                    }
                }
                else if (subChoice == 2)
                {
                    printf("\n------ ขนมที่มี ------\n");
                    printf("1. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", snackName1, snackQty1, snackPrice1);
                    printf("2. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", snackName2, snackQty2, snackPrice2);
                    printf("3. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", snackName3, snackQty3, snackPrice3);
                    printf("เลือกสินค้า: ");
                    if (scanf("%d", &choiceNum) != 1)
                    {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n')
                            ;
                        continue;
                    }
                    while (getchar() != '\n')
                        ;

                    if (choiceNum >= 1 && choiceNum <= 3)
                    {
                        printf("จำนวนที่ต้องการ: ");
                        if (scanf("%d", &qty) != 1)
                        {
                            printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                            while (getchar() != '\n')
                                ;
                            continue;
                        }
                        while (getchar() != '\n')
                            ;
                        if (qty > 0)
                        {
                            if (choiceNum == 1 && qty <= snackQty1)
                            {
                                snackQty1 -= qty;
                                total += snackPrice1 * qty;
                                printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", snackName1, qty);
                            }
                            else if (choiceNum == 2 && qty <= snackQty2)
                            {
                                snackQty2 -= qty;
                                total += snackPrice2 * qty;
                                printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", snackName2, qty);
                            }
                            else if (choiceNum == 3 && qty <= snackQty3)
                            {
                                snackQty3 -= qty;
                                total += snackPrice3 * qty;
                                printf("เพิ่ม %s %d ชิ้นลงในตะกร้า\n", snackName3, qty);
                            }
                            else
                            {
                                printf("จำนวนไม่ถูกต้องหรือสินค้าไม่พอ\n");
                            }
                        }
                        else
                        {
                            printf("จำนวนไม่ถูกต้องหรือสินค้าไม่พอ\n");
                        }
                    }
                    else
                    {
                        printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                    }
                }
                else if (subChoice != 0)
                {
                    printf("ตัวเลือกประเภทสินค้าไม่ถูกต้อง\n");
                }
            } while (subChoice != 0);

            if (total > 0)
            {
                printf("\n------ ชำระเงิน ------\n");
                printf("ยอดรวมทั้งหมด: %.2f บาท\n", total);
                printf("กรุณาใส่เงิน: ");
                if (scanf("%lf", &paid) != 1)
                {
                    printf("กรุณาใส่จำนวนเงินที่ถูกต้อง\n");
                    while (getchar() != '\n')
                        ;
                }

                if (paid < total)
                {
                    printf("เงินไม่พอ! รายการถูกยกเลิก\n");
                }
                else
                {
                    change = paid - total;
                    printf("การชำระเงินสำเร็จ\n");
                    printf("เงินทอน: %.2f บาท\n", change);

                    int int_change = (int)(change + 0.5); // ปัดเศษเงินทอนให้เป็นจำนวนเต็ม
                    int count;

                    // ทอนเงินโดยหักจากสต็อกแบงค์และเหรียญ
                    int remain = int_change;
                    int used1000 = 0, used500 = 0, used100 = 0, used50 = 0, used20 = 0;
                    int used10 = 0, used5 = 0, used2 = 0, used1 = 0;

                    if (remain >= 1000 && stock1000 > 0) {
                        count = remain / 1000;
                        if (count > stock1000) count = stock1000;
                        used1000 = count;
                        remain -= 1000 * count;
                    }
                    if (remain >= 500 && stock500 > 0) {
                        count = remain / 500;
                        if (count > stock500) count = stock500;
                        used500 = count;
                        remain -= 500 * count;
                    }
                    if (remain >= 100 && stock100 > 0) {
                        count = remain / 100;
                        if (count > stock100) count = stock100;
                        used100 = count;
                        remain -= 100 * count;
                    }
                    if (remain >= 50 && stock50 > 0) {
                        count = remain / 50;
                        if (count > stock50) count = stock50;
                        used50 = count;
                        remain -= 50 * count;
                    }
                    if (remain >= 20 && stock20 > 0) {
                        count = remain / 20;
                        if (count > stock20) count = stock20;
                        used20 = count;
                        remain -= 20 * count;
                    }
                    if (remain >= 10 && stock10 > 0) {
                        count = remain / 10;
                        if (count > stock10) count = stock10;
                        used10 = count;
                        remain -= 10 * count;
                    }
                    if (remain >= 5 && stock5 > 0) {
                        count = remain / 5;
                        if (count > stock5) count = stock5;
                        used5 = count;
                        remain -= 5 * count;
                    }
                    if (remain >= 1 && stock1 > 0) {
                        count = remain / 1;
                        if (count > stock1) count = stock1;
                        used1 = count;
                        remain -= 1 * count;
                    }

                    if (remain == 0) {
                        if (used1000) { printf("ธนบัตร 1000 บาท = %d ใบ\n", used1000); stock1000 -= used1000; }
                        if (used500)  { printf("ธนบัตร 500 บาท = %d ใบ\n", used500); stock500 -= used500; }
                        if (used100)  { printf("ธนบัตร 100 บาท = %d ใบ\n", used100); stock100 -= used100; }
                        if (used50)   { printf("ธนบัตร 50 บาท = %d ใบ\n", used50); stock50 -= used50; }
                        if (used20)   { printf("ธนบัตร 20 บาท = %d ใบ\n", used20); stock20 -= used20; }
                        if (used10)   { printf("เหรียญ 10 บาท = %d เหรียญ\n", used10); stock10 -= used10; }
                        if (used5)    { printf("เหรียญ 5 บาท = %d เหรียญ\n", used5); stock5 -= used5; }
                        if (used1)    { printf("เหรียญ 1 บาท = %d เหรียญ\n", used1); stock1 -= used1; }
                        printf("สินค้าถูกจัดส่งแล้ว\n");
                    } else {
                        printf("ขออภัย ระบบไม่มีเงินทอนเพียงพอ กรุณาติดต่อเจ้าหน้าที่\n");
                    }
                }
            }
            printf("\nขอบคุณที่ใช้บริการ!\n");
        }
        else if (mainChoice == 2)
        {
            printf("\n--- Admin System ---\n");
            printf("1. เติมสต็อกเครื่องดื่ม\n");
            printf("2. เติมสต็อกขนม\n");
            printf("3. ดูสต็อกเครื่องดื่ม\n");
            printf("4. ดูสต็อกขนม\n");
            printf("5. เติมสต็อกแบงค์/เหรียญ\n");
            printf("6. ดูสต็อกแบงค์/เหรียญ\n");
            printf("7. กลับสู่เมนูหลัก\n");
            printf("เลือกเมนู: ");
            if (scanf("%d", &subChoice) != 1)
            {
                printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            while (getchar() != '\n')
                ;

            if (subChoice == 1)
            {
                printf("\n--- เติมสต็อกเครื่องดื่ม ---\n");
                printf("1. %s (เหลือ %d ชิ้น)\n", drinkName1, drinkQty1);
                printf("2. %s (เหลือ %d ชิ้น)\n", drinkName2, drinkQty2);
                printf("3. %s (เหลือ %d ชิ้น)\n", drinkName3, drinkQty3);
                printf("4. %s (เหลือ %d ชิ้น)\n", drinkName4, drinkQty4);
                printf("เลือกสินค้าที่จะเติมสต็อก: ");
                if (scanf("%d", &choiceNum) != 1)
                {
                    printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                while (getchar() != '\n')
                    ;
                if (choiceNum >= 1 && choiceNum <= 4)
                {
                    printf("จำนวนที่ต้องการเพิ่ม: ");
                    if (scanf("%d", &qty) != 1)
                    {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n')
                            ;
                        continue;
                    }
                    while (getchar() != '\n')
                        ;
                    if (qty > 0)
                    {
                        if (choiceNum == 1)
                        {
                            drinkQty1 += qty;
                            printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", drinkName1, qty);
                        }
                        else if (choiceNum == 2)
                        {
                            drinkQty2 += qty;
                            printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", drinkName2, qty);
                        }
                        else if (choiceNum == 3)
                        {
                            drinkQty3 += qty;
                            printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", drinkName3, qty);
                        }
                        else if (choiceNum == 4)
                        {
                            drinkQty4 += qty;
                            printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", drinkName4, qty);
                        }
                    }
                    else
                    {
                        printf("จำนวนที่เพิ่มไม่ถูกต้อง\n");
                    }
                }
                else
                {
                    printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                }
            }
            else if (subChoice == 2)
            {
                printf("\n--- เติมสต็อกขนม ---\n");
                printf("1. %s (เหลือ %d ชิ้น)\n", snackName1, snackQty1);
                printf("2. %s (เหลือ %d ชิ้น)\n", snackName2, snackQty2);
                printf("3. %s (เหลือ %d ชิ้น)\n", snackName3, snackQty3);
                printf("เลือกสินค้าที่จะเติมสต็อก: ");
                if (scanf("%d", &choiceNum) != 1)
                {
                    printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                while (getchar() != '\n')
                    ;
                if (choiceNum >= 1 && choiceNum <= 3)
                {
                    printf("จำนวนที่ต้องการเพิ่ม: ");
                    if (scanf("%d", &qty) != 1)
                    {
                        printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                        while (getchar() != '\n')
                            ;
                        continue;
                    }
                    while (getchar() != '\n')
                        ;
                    if (qty > 0)
                    {
                        if (choiceNum == 1)
                        {
                            snackQty1 += qty;
                            printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", snackName1, qty);
                        }
                        else if (choiceNum == 2)
                        {
                            snackQty2 += qty;
                            printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", snackName2, qty);
                        }
                        else if (choiceNum == 3)
                        {
                            snackQty3 += qty;
                            printf("เติมสต็อก %s อีก %d ชิ้นเรียบร้อยแล้ว\n", snackName3, qty);
                        }
                    }
                    else
                    {
                        printf("จำนวนที่เพิ่มไม่ถูกต้อง\n");
                    }
                }
                else
                {
                    printf("หมายเลขสินค้าไม่ถูกต้อง\n");
                }
            }
            else if (subChoice == 3)
            {
                printf("\n--- สต็อกเครื่องดื่ม ---\n");
                printf("1. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName1, drinkQty1, drinkPrice1);
                printf("2. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName2, drinkQty2, drinkPrice2);
                printf("3. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName3, drinkQty3, drinkPrice3);
                printf("4. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", drinkName4, drinkQty4, drinkPrice4);
            }
            else if (subChoice == 4)
            {
                printf("\n--- สต็อกขนม ---\n");
                printf("1. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", snackName1, snackQty1, snackPrice1);
                printf("2. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", snackName2, snackQty2, snackPrice2);
                printf("3. %s (เหลือ %d ชิ้น) ราคา %.2f บาท\n", snackName3, snackQty3, snackPrice3);
            }
            else if (subChoice == 5)
            {
                printf("\n--- เติมสต็อกแบงค์/เหรียญ ---\n");
                printf("1. ธนบัตร 1000 บาท (เหลือ %d ใบ)\n", stock1000);
                printf("2. ธนบัตร 500 บาท (เหลือ %d ใบ)\n", stock500);
                printf("3. ธนบัตร 100 บาท (เหลือ %d ใบ)\n", stock100);
                printf("4. ธนบัตร 50 บาท (เหลือ %d ใบ)\n", stock50);
                printf("5. ธนบัตร 20 บาท (เหลือ %d ใบ)\n", stock20);
                printf("6. เหรียญ 10 บาท (เหลือ %d เหรียญ)\n", stock10);
                printf("7. เหรียญ 5 บาท (เหลือ %d เหรียญ)\n", stock5);
                printf("9. เหรียญ 1 บาท (เหลือ %d เหรียญ)\n", stock1);
                printf("เลือกชนิดเงินที่ต้องการเติม: ");
                if (scanf("%d", &choiceNum) != 1)
                {
                    printf("กรุณาใส่ตัวเลขที่ถูกต้อง\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                printf("จำนวนที่ต้องการเพิ่ม: ");
                if (scanf("%d", &qty) != 1 || qty <= 0)
                {
                    printf("จำนวนไม่ถูกต้อง\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                switch (choiceNum)
                {
                case 1: stock1000 += qty; break;
                case 2: stock500 += qty; break;
                case 3: stock100 += qty; break;
                case 4: stock50 += qty; break;
                case 5: stock20 += qty; break;
                case 6: stock10 += qty; break;
                case 7: stock5 += qty; break;
                case 8: stock1 += qty; break;
                default: printf("หมายเลขไม่ถูกต้อง\n"); break;
                }
                printf("เติมสต็อกเรียบร้อยแล้ว\n");
            }
            else if (subChoice == 6)
            {
                printf("\n--- สต็อกแบงค์/เหรียญ ---\n");
                printf("ธนบัตร 1000 บาท = %d ใบ\n", stock1000);
                printf("ธนบัตร 500 บาท = %d ใบ\n", stock500);
                printf("ธนบัตร 100 บาท = %d ใบ\n", stock100);
                printf("ธนบัตร 50 บาท = %d ใบ\n", stock50);
                printf("ธนบัตร 20 บาท = %d ใบ\n", stock20);
                printf("เหรียญ 10 บาท = %d เหรียญ\n", stock10);
                printf("เหรียญ 5 บาท = %d เหรียญ\n", stock5);
                printf("เหรียญ 1 บาท = %d เหรียญ\n", stock1);
            }
            else if (subChoice != 7)
            {
                printf("ตัวเลือกไม่ถูกต้อง\n");
            }
        }
        else if (mainChoice == 3)
        {
            printf("ออกจากโปรแกรม\n");
            break;
        }
        else
        {
            printf("ตัวเลือกไม่ถูกต้อง กรุณาเลือกอีกครั้ง\n");
        }
    }

    return 0;
}