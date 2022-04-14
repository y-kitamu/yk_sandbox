/*
 * main.cpp
 *
 * Create Date : 2022-04-13 21:29:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>
#include <filesystem>

#include <tiff.h>
#include <tiffio.h>
#include <argparse/argparse.hpp>
#include <opencv2/opencv.hpp>

#include "core.hpp"

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    argparse::ArgumentParser program("main");
    program.add_argument("input_tiff");
    program.add_argument("output_tiff");

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    fs::path input = program.get("input_tiff");
    fs::path output = program.get("output_tiff");
    yk_debug("input path = {}", input.string());

    {
        TIFF* tif = TIFFOpen(output.string().c_str(), "w");
        if (tif) {
            uint32_t image_width = 256, image_height = 512;
            uint32_t tile_width = 256, tile_height = 512;

            std::vector<uint8_t> buf(image_width * image_height / 8, 0);
            for (int y = 0; y < image_height / 8; y++) {
                for (int x = 0; x < image_width / 8; x++) {
                    buf[y * image_width / 8 + x] = 255;
                }
            }

            TIFFSetField(tif, TIFFTAG_IMAGEWIDTH, image_width);
            TIFFSetField(tif, TIFFTAG_IMAGELENGTH, image_height);
            TIFFSetField(tif, TIFFTAG_BITSPERSAMPLE, 1);
            TIFFSetField(tif, TIFFTAG_COMPRESSION, 4);
            TIFFSetField(tif, TIFFTAG_TILEWIDTH, tile_width);
            TIFFSetField(tif, TIFFTAG_TILELENGTH, tile_height);

            for (int y = 0; y < image_height; y += tile_height) {
                for (int x = 0; x < image_width; x += tile_width) {
                    int offset = y * tile_width / 8 + x / 8;
                    TIFFWriteTile(tif, buf.data() + offset, x, y, 0, 0);
                }
            }
            TIFFClose(tif);
        }
    }

    {
        cv::Mat src(256, 256, CV_8UC1, cv::Scalar(0));
        cv::Mat image;
        cv::resize(src, image, cv::Size(512, 512));
        cv::imwrite("test.png", image);
        cv::imwrite("test.jpeg", image);
        cv::imwrite("test.tiff", image);
    }
    yk_debug("Finish output : {}", output.string());
}
