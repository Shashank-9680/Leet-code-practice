<h2><a href="https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1">Maximum Difference</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 12pt;">Given an integer array <strong>arr </strong>of<strong> </strong>integers, the task is to find the maximum absolute difference between the nearest <strong>left smaller</strong> element and the nearest <strong>right smaller </strong>element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.</span></p>
<p><span style="font-size: 12pt;"><strong>Examples :</strong></span></p>
<pre style="position: relative;"><span style="font-size: 12pt;"><strong>Input: </strong>arr = [2, 1, 8]
<strong>Output:</strong> 1<br><strong>Explanation: </strong>left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>
<pre style="position: relative;"><span style="font-size: 12pt;"><strong>Input: </strong>arr = [2, 4, 8, 7, 7, 9, 3]
<strong>Output:</strong> 4<br><strong>Explanation:</strong> left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>
<p><span style="font-size: 12pt;"><strong>Expected Time Complexity: </strong>O(n)<br><strong>Expected Space&nbsp;</strong></span><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: 16px;">Complexity</strong><strong style="font-size: 12pt; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">:</strong><span style="font-size: 12pt; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"> O(n)</span></p>
<p><span style="font-size: 12pt;"><strong>Constraints:</strong><br>1 &lt;= arr.size() &lt;= 10<sup>6</sup><br>1&lt;= arr[i] &lt;=10<sup>9</sup><br></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;