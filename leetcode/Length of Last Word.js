/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
 
    s = s.trim();
 
     var s_s = s.split(" ");
   
    return s_s[s_s.length -1].length;
};