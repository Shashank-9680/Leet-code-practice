#include <string>
using namespace std;

class Solution {
   string arr1[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
   string arr2[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
   string arr3[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
   
   string change(int num) {
       if (num == 0) {
           return "";
       }
       if (num < 10) {
           return arr1[num];
       }
       if (num < 20) {
           return arr2[num - 10];
       }
       if (num < 100) {
           string ans = arr3[num / 10];
           if (num % 10 != 0) {
               ans += " " + arr1[num % 10];
           }
           return ans;
       }
       if (num < 1000) {
           string ans = arr1[num / 100] + " Hundred";
           if (num % 100 != 0) {
               ans += " " + change(num % 100);
           }
           return ans;
       }
       if (num < 1000000) {
           string ans = change(num / 1000) + " Thousand";
           if (num % 1000 != 0) {
               ans += " " + change(num % 1000);
           }
           return ans;
       }
       if (num < 1000000000) {
           string ans = change(num / 1000000) + " Million";
           if (num % 1000000 != 0) {
               ans += " " + change(num % 1000000);
           }
           return ans;
       }
       string ans = change(num / 1000000000) + " Billion";
       if (num % 1000000000 != 0) {
           ans += " " + change(num % 1000000000);
       }
       return ans;
   }
   
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return change(num);
    }
};
