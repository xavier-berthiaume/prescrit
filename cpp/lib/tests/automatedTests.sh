#!/bin/bash

RELATIVE_PATH="../build"
OUTPUT_FILE="TestOutput"
TEST_REPS=100

cd $RELATIVE_PATH
mkdir "${RELATIVE_PATH}/core-dumps"
touch "${RELATIVE_PATH}/${OUTPUT_FILE}"

echo "" > $OUTPUT_FILE

current_test=0

while [ $current_test -le $TEST_REPS ]
do

    echo "<<<---      Test #${current_test}      --->>>" >> $OUTPUT_FILE
    ./tests/functional-testing/patientTest Xavier Berthiaume 13 4 1997 >> $OUTPUT_FILE 2>&1
    echo "" >> $OUTPUT_FILE
    echo "" >> $OUTPUT_FILE
    echo "" >> $OUTPUT_FILE

    if [ -f "${RELATIVE_PATH}/core-dumps/core" ]; then

        mv "${RELATIVE_PATH}/core-dumps/core" "${RELATIVE_PATH}/core-dumps/core-${current_test}"
    fi

    ((current_test++))
done
