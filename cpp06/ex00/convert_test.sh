#!/bin/bash

# Function to run a test case
run_test() {
    input="$1"
    expected_output="$2"

    echo -n "Testing ./convert \"$input\" ... "

    # Run the program and capture output
    actual_output=$(./convert "$input" | grep "int:" | xargs)

    # Compare actual vs expected output
    if [ "$actual_output" == "$expected_output" ]; then
        echo "✅ Passed"
    else
        echo "❌ Failed"
        echo "   Expected: $expected_output"
        echo "   Got:      $actual_output"
        exit 1  # Stop execution on failure
    fi
}

# Test cases int
run_test "42" "int: 42"
run_test "43.5" "int: impossible"
run_test "+0" "int: 0"
run_test "nanf" "int: impossible"
run_test "1.00000000000f" "int: 1"

echo "🎉 All tests passed!"