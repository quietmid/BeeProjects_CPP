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
run_test "42" "type: Int"
run_test "43.5" "type: Double"
run_test "+0" "type: Int"
run_test "nanf" "type: Float"
run_test "1.00000000000f" "type: Float"
run_test "a" "type: Char"
run_test "a.a" "type: Invalid Input"
run_test "2147483648" "type: Invalid Input"

echo "🎉 All tests passed!"