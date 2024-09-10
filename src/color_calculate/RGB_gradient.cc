/*
 * @Author: jk_zeng@qq.com
 * @Date: 2024-09-09 16:00:00
 * @LastEditors: jk_zeng@qq.com
 * @LastEditTime: 2024-09-10 10:22:01
 * @FilePath: /Technical-Verification/src/color_calculate/RGB_gradient.cc
 * @Description: 
 * 
 * Copyright (c) 2024 by ${jk_zeng@qq.com}, All Rights Reserved. 
 */
#include "color_calculate/RGB_gradient.h"

RGBgradient::RGBgradient(double max, double min):
        max_(max), min_(min)
{
}

RGBgradient::~RGBgradient()
{
}

RGBgradient::RGB RGBgradient::CalculateRGB(double num){
    RGBgradient::RGB rgb;
    if ((num-min_)<(max_-min_)/6){
        rgb.red = 255;
        rgb.green = 152*(num-min_)/((max_-min_)/6);
        rgb.blue = 0;
    }else if(((num-min_)>=(max_-min_)/6)&&((num-min_)<(max_-min_)/3)){
        rgb.red = 255;
        rgb.green = 152 + 102 * (num - (min_ + (max_ - min_) / 6)) / ((max_ - min_) / 6);
        rgb.blue = 0;
    }else if(((num-min_)>=(max_-min_)/3)&&((num-min_)<(max_-min_)/2)){
        rgb.red = 255 - 255 * (num - (min_ + (max_ - min_) / 3)) / ((max_ - min_) / 6);
        rgb.green = 255;
        rgb.blue = 0;
    }else if(((num-min_)>=(max_-min_)/2)&&((num-min_)<(max_-min_)*2/3)){
        rgb.red = 0;
        rgb.green = 255;
        rgb.blue = 255 * (num - (min_ + (max_ - min_) / 2)) / ((max_ - min_) / 6);
    }else if(((num-min_)>=(max_-min_)*2/3)&&((num-min_)<(max_-min_)*5/6)){
        rgb.red = 0;
        rgb.green = 255 - 255 * (num - (min_ + (max_ - min_) *2 / 3)) / ((max_ - min_) / 6);
        rgb.blue = 255;
    }else if(((num-min_)>=(max_-min_)*5/6)&&((num-min_)<(max_-min_))){
        rgb.red = 150 * (num - (min_ + (max_ - min_)*5/6)) / ((max_ - min_) / 6);
        rgb.green = 0;
        rgb.blue = 255;
    }else if(num<min_){
        rgb.red = 255;
        rgb.green = 0;
        rgb.blue = 0;
    }else{
        rgb.red = 150;
        rgb.green = 0;
        rgb.blue = 255;
    }
    
    return rgb;
}