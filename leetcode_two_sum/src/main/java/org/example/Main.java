package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
class Solution {

    public int[] twoSum(int[] nums, int target) {

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {

                int c = nums[i] + nums[j];
                if (c == target) {
                    int[] b = { i, j };

                    return b;

                }

            }
        }
        return new int[] {};

    }
}