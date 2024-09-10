/*
 * @Author: jk_zeng@qq.com
 * @Date: 2024-09-09 16:00:16
 * @LastEditors: jk_zeng@qq.com
 * @LastEditTime: 2024-09-10 09:54:47
 * @FilePath: /Technical-Verification/src/color_calculate/RGB_gradient.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${jk_zeng@qq.com}, All Rights Reserved. 
 */

// 计算RGB渐变色
class RGBgradient   
{

public:
    struct RGB{
        double red;
        double green;
        double blue;
    };

    RGBgradient(double max, double min);
    ~RGBgradient();

    RGB CalculateRGB(double num);

private:
    double max_,min_;
};


