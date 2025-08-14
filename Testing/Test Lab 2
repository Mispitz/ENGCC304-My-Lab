#include <stdio.h>
#include <string.h>

int main() {
    char choice[5]; 
    char itemType, itemChoice, continue_choice;
    char cart_items[20][50]; 
    double cart_prices[20];
    int cart_count = 0; 
    double total = 0.0; 
    double amountPaid = 0.0; 
    double changeDue = 0.0; 
    int i; 

    printf("ยินดีต้อนรับสู่เครื่องจำหน่ายสินค้าอัตโนมัติ!\n");

    // ลูปหลักของโปรแกรม จะทำงานแค่ครั้งเดียว
    while (1) { 
        // แสดงเมนูหลักให้ลูกค้าเลือก
        printf("\n--- เมนูหลัก ---\n");
        printf("1. ซื้อขนมหรือเครื่องดื่ม\n");
        printf("2. ออกจากโปรแกรม\n");
        printf("-----------------\n");
        printf("กรุณาเลือกตัวเลือก (1 เพื่อซื้อ, 2 เพื่อออก): ");
        scanf("%s", choice); 

        // ตรวจสอบว่าผู้ใช้ต้องการออกจากโปรแกรมหรือไม่
        if (strcmp(choice, "2") == 0) {
            break; 
        }

        // ถ้าผู้ใช้เลือกที่จะซื้อสินค้า
        if (strcmp(choice, "1") == 0) {
            cart_count = 0;
            total = 0.0;
            
            // ลูปนี้จะให้ลูกค้าเลือกซื้อสินค้าได้หลายรายการจนกว่าจะพอใจ
            while (1) {
                // ให้ผู้ใช้เลือกประเภทสินค้า
                printf("\nเลือกประเภทสินค้า:\n");
                printf("1. เครื่องดื่ม\n");
                printf("2. ขนม\n");
                printf("ใส่ตัวเลือกของคุณ: ");
                scanf(" %c", &itemType); 

                // ตรวจสอบประเภทสินค้าที่เลือกว่าเป็นเครื่องดื่ม
                if (itemType == '1') {
                    printf("\nเครื่องดื่มที่มี:\n");
                    printf("a. โค้ก (10 บาท)\n");
                    printf("b. น้ำเขียว (12 บาท)\n");
                    printf("c. ลาเต้ (35 บาท)\n");
                    printf("d. อเมริกาโน่ (30 บาท)\n");
                    printf("ใส่ตัวเลือกของคุณ: ");
                    scanf(" %c", &itemChoice);

                    // เพิ่มสินค้าที่เลือกในตะกร้า
                    if (itemChoice == 'a') {
                        strcpy(cart_items[cart_count], "โค้ก"); 
                        cart_prices[cart_count] = 10.0;
                        cart_count++;
                        printf("เพิ่มโค้กลงในตะกร้าแล้ว\n");
                    } else if (itemChoice == 'b') {
                        strcpy(cart_items[cart_count], "น้ำเขียว");
                        cart_prices[cart_count] = 12.0;
                        cart_count++;
                        printf("เพิ่มน้ำเขียวลงในตะกร้าแล้ว\n");
                    } else if (itemChoice == 'c') {
                        strcpy(cart_items[cart_count], "ลาเต้");
                        cart_prices[cart_count] = 35.0;
                        cart_count++;
                        printf("เพิ่มลาเต้ลงในตะกร้าแล้ว\n");
                    } else if (itemChoice == 'd') {
                        strcpy(cart_items[cart_count], "อเมริกาโน่");
                        cart_prices[cart_count] = 30.0;
                        cart_count++;
                        printf("เพิ่มอเมริกาโน่ลงในตะกร้าแล้ว\n");
                    } else {
                        printf("ตัวเลือกเครื่องดื่มไม่ถูกต้อง\n");
                    }
                }
                // ตรวจสอบประเภทสินค้าที่เลือกว่าเป็นขนม
                else if (itemType == '2') {
                    printf("\nขนมที่มี:\n");
                    printf("a. เมล็ดทานตะวัน (13 บาท)\n");
                    printf("b. ถั่วแปบ (20 บาท)\n");
                    printf("c. จิ้นส้มหมก (16 บาท)\n");
                    printf("ใส่ตัวเลือกของคุณ: ");
                    scanf(" %c", &itemChoice);

                    // เพิ่มสินค้าที่เลือกในตะกร้า
                    if (itemChoice == 'a') {
                        strcpy(cart_items[cart_count], "เมล็ดทานตะวัน");
                        cart_prices[cart_count] = 13.0;
                        cart_count++;
                        printf("เพิ่มเมล็ดทานตะวันลงในตะกร้าแล้ว\n");
                    } else if (itemChoice == 'b') {
                        strcpy(cart_items[cart_count], "ถั่วแปบ");
                        cart_prices[cart_count] = 20.0;
                        cart_count++;
                        printf("เพิ่มถั่วแปบลงในตะกร้าแล้ว\n");
                    } else if (itemChoice == 'c') {
                        strcpy(cart_items[cart_count], "จิ้นส้มหมก");
                        cart_prices[cart_count] = 16.0;
                        cart_count++;
                        printf("เพิ่มจิ้นส้มหมกลงในตะกร้าแล้ว\n");
                    } else {
                        printf("ตัวเลือกขนมไม่ถูกต้อง\n");
                    }
                } 
                // กรณีเลือกประเภทสินค้าไม่ถูกต้อง
                else {
                    printf("ตัวเลือกประเภทสินค้าไม่ถูกต้อง\n");
                }

                // ถามผู้ใช้ว่าต้องการซื้อสินค้าเพิ่มอีกหรือไม่
                printf("\nต้องการเพิ่มสินค้าอีกหรือไม่? (Y/N): ");
                scanf(" %c", &continue_choice);
                if (continue_choice == 'N' || continue_choice == 'n') {
                    break; 
                }
            }

            // ถ้ามีสินค้าในตะกร้า จะเข้าสู่ขั้นตอนการชำระเงิน
            if (cart_count > 0) {
                // แสดงรายการสินค้าในตะกร้าทั้งหมด
                printf("\n--- ตะกร้าสินค้าของคุณ ---\n");
                for (i = 0; i < cart_count; i++) {
                    printf("%s: %.2f บาท\n", cart_items[i], cart_prices[i]);
                    total += cart_prices[i];
                }
                printf("ยอดรวมที่ต้องชำระ: %.2f บาท\n", total);
                printf("-----------------\n");

                printf("กรุณาหยอดเงิน: ");
                scanf("%lf", &amountPaid); 

                // ตรวจสอบจำนวนเงินที่หยอดว่าเพียงพอหรือไม่
                if (amountPaid < total) {
                    printf("เงินไม่พอ การทำรายการถูกยกเลิก\n");
                } else {
                    changeDue = amountPaid - total; 

                    printf("\nยอดเงินที่จ่าย: %.2f บาท\n", amountPaid);
                    printf("เงินทอนของคุณคือ: %.2f บาท\n", changeDue);

                    // ตรวจสอบว่าต้องทอนเงินหรือไม่
                    if (changeDue > 0) {
                        printf("\n--- กำลังทอนเงิน ---\n");
                        printf("กำลังทอนเงินจำนวน %.2f บาท\n", changeDue);
                        printf("กรุณารับเงินทอนของคุณจากช่องด้านล่าง\n");
                    } else {
                        printf("ไม่ต้องทอนเงิน จ่ายพอดี\n");
                    }

                    // จ่ายสินค้า
                    printf("\n--- กำลังจ่ายสินค้า ---\n");
                    printf("กรุณารับสินค้าจากช่องด้านล่าง:\n");
                    for (i = 0; i < cart_count; i++) {
                        printf("- %s\n", cart_items[i]);
                    }
                }
            }
        } 
        // ถ้าผู้ใช้เลือกตัวเลือกในเมนูหลักไม่ถูกต้อง
        else {
            printf("ตัวเลือกไม่ถูกต้อง กรุณาลองใหม่อีกครั้ง\n");
        }
        
        // เมื่อการทำรายการเสร็จสิ้น จะออกจากลูปทันที
        printf("\nขอบคุณที่ใช้บริการ!\n");
        return 0; // จบการทำงานของโปรแกรม
    }

    printf("ขอบคุณที่ใช้บริการ!\n");
    return 0; // จบการทำงานของโปรแกรม (ในกรณีที่เลือก 2 เพื่อออกตั้งแต่แรก)
}