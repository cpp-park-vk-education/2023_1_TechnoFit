mkdir build_opencv && cd build_opencv && cmake ../opencv-4.x && cmake --build .
cd ../

export OpenCV_DIR=../build_opencv

echo "Successfully built!"
