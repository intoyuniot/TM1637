#include <TM1637.h>

//引脚定义
#define CLK 2
#define DIO 3

//测试时间
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
    SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
    SEG_C | SEG_E | SEG_G,                           // n
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

TM1637 display(CLK, DIO);

void setup()
{
}

void loop()
{
    int k;
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    display.setBrightness(0x0f);

    // 所有段显示
    display.setSegments(data);
    delay(TEST_DELAY);

    //选择设置不同的位
    data[0] = 0b01001001;
    data[1] = display.encodeDigit(1);
    data[2] = display.encodeDigit(2);
    data[3] = display.encodeDigit(3);

    for(k = 3; k >= 0; k--)
    {
        display.setSegments(data, 1, k);
        delay(TEST_DELAY);
    }

    display.setSegments(data+2, 2, 2);
    delay(TEST_DELAY);

    display.setSegments(data+2, 2, 1);
    delay(TEST_DELAY);

    display.setSegments(data+1, 3, 1);
    delay(TEST_DELAY);


    //显示十进制数
    bool lz = false;
    for (uint8_t z = 0; z < 2; z++)
    {
        for(k = 0; k < 10000; k += k*4 + 7)
        {
            display.showNumberDec(k, lz);
            delay(TEST_DELAY);
        }

        lz = true;
    }

    //显示水机制数其长度小于4
    for(k = 0; k < 4; k++)
        data[k] = 0;
    display.setSegments(data);

    display.showNumberDec(153, false, 3, 1);
    delay(TEST_DELAY);
    display.showNumberDec(22, false, 2, 2);
    delay(TEST_DELAY);
    display.showNumberDec(0, true, 1, 3);
    delay(TEST_DELAY);
    display.showNumberDec(0, true, 1, 2);
    delay(TEST_DELAY);
    display.showNumberDec(0, true, 1, 1);
    delay(TEST_DELAY);
    display.showNumberDec(0, true, 1, 0);
    delay(TEST_DELAY);

    //亮度测试
    for(k = 0; k < 4; k++)
        data[k] = 0xff;
    for(k = 0; k < 16; k++)
    {
        display.setBrightness(k);
        display.setSegments(data);
        delay(TEST_DELAY);
    }


    display.setSegments(SEG_DONE);

    while(1);
}
