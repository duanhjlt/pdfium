#!/bin/bash

cd build/gyp/
git push github

cd ../../testing/corpus
git push github

cd ../gmock
git push github

cd ../gtest
git push github

cd ../../v8
git push github

cd third_party/icu
git push github

cd ../cygwin
git push github

cd ../../../
git push github
