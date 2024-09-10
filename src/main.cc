/*
 * @Author: jk_zeng@qq.com
 * @Date: 2024-09-09 13:25:49
 * @LastEditors: jk_zeng@qq.com
 * @LastEditTime: 2024-09-10 11:22:50
 * @FilePath: /Technical-Verification/src/main.cc
 * @Description: 
 * 
 * Copyright (c) 2024 by ${jk_zeng@qq.com}, All Rights Reserved. 
 */
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include "glog/logging.h"

#include "color_calculate/RGB_gradient.h"

void PointCloudVisual(){
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointXYZRGB point;
    pcl::visualization::CloudViewer viewer("cloud viewer");
    RGBgradient rgb_calculate(2,0);

    int i = 0;
    while (!viewer.wasStopped())
    {
        point.x = sin(((double)i/100));
        point.y = cos(((double)i/100));
        point.z = ((double)i/314);
        RGBgradient::RGB rgb = rgb_calculate.CalculateRGB((double)i/314);
        point.r = rgb.red;
        point.g = rgb.green;
        point.b = rgb.blue;
        cloud->push_back(point);
        viewer.showCloud(cloud);
        LOG(INFO) << "----------" << i << "----------";
        usleep(100000);
        i++;
    }
}

int main(int argc, char **argv){
    
    PointCloudVisual();

    return 0;
}