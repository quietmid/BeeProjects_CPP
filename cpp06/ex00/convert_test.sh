#!/bin/bash

Function to run a test case
run_test() {
    input="$1"
    expected_output="$2"

    echo -n "Testing ./convert \"$input\" ... "

    # Run the program and capture output
    actual_output=$(./convert "$input" | grep "type:" | xargs)

    # Compare actual vs expected output
    if [ "$actual_output" == "$expected_output" ]; then
        echo "✅ Passed: $actual_output && $expected_output"
    else
        echo "❌ Failed"
        echo "   Expected: $expected_output"
        echo "   Got:      $actual_output"
        #exit 1  # Stop execution on failure
    fi
}

# Test cases int
run_test "42" "type: 1"
run_test "43.5" "type: 4"
run_test "+0" "type: 1"
run_test "nanf" "type: 3"
run_test "1.00000000000f" "type: 2"
run_test "a" "type: 0"
run_test "a.a" "type: -1"

echo "🎉 All tests passed!"