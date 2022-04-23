gcc -D UNITY_EXCLUDE_MATH_H -D UNITY_EXCLUDE_FLOAT buffer.c buffer_test.c Unity/src/unity.c -o buffer_test
./buffer_test
rm buffer_test
