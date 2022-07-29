class Solution:
    # String to numeric string
    def _generate_pattern_map(self,s):
        s_map = {}
        unique_number = 0
        ret_numeric_string = ""
        ret_numeric_list = []
        for i in range(len(s)):
            if s[i] == " ":
                continue
            if s[i] not in s_map:
                unique_number+=1
                s_map[s[i]] = unique_number
                ret_numeric_list.append(s_map[s[i]])
            else:
                ret_numeric_list.append(s_map[s[i]])
        return ret_numeric_list
    
    def findAndReplacePattern(self, words , pattern):
        numeric_pattern_list = self._generate_pattern_map(pattern)
        ret_list = []
        for i in range(len(words)):
            word_numeric_list= self._generate_pattern_map(words[i])
            if word_numeric_list==numeric_pattern_list:
                ret_list.append(words[i])
        return ret_list


input_words = ["abcdefghijklab","abcdefghijkabl"]
input_pattern = "abcdefghijklab"
sol = Solution()
print("Sol=", sol.findAndReplacePattern(input_words,input_pattern))







