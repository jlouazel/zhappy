#!/bin/sh
find . -type f -name "*.material" -exec sed -i "s/ambient 0 0 0 1/                        ambient 0.8 0.8 0.8\n                        diffuse 0.8 0.8 0.8\n                        specular 1 1 1 8/g" {} \;
