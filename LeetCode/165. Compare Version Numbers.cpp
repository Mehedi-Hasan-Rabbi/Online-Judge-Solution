class Solution {
public:
    int matchDot(string &version1, string &version2) {
        int dot1 = 0, dot2 = 0;
        for (auto &u: version1)
            if (u == '.')
                dot1++;
    
        for (auto &u: version2)
            if (u == '.')
                dot2++;
    
        while (dot1 < dot2) {
            version1 = version1 + ".0"; 
            dot1++;
        }
        while (dot1 > dot2) {
            version2 = version2 + ".0"; 
            dot2++;
        }

        // Putting extra dot for to make calculation easy
        version1 += ".";    dot1++;
        version2 += ".";    dot2++;

        return dot1;
    }

    int compareVersion(string version1, string version2) {
        int dot = matchDot(version1, version2);
        int d = 0;

        int i = 0, j = 0;
        while (d < dot) {
            int x = 0, y = 0;
            string v1 = "", v2 = "";
            // Version 1
            while (i < (int) version1.size()) {
                if (version1[i] == '.') {i++; break;}

                v1 += version1[i];
                i++;
            }
            // Version 1
            while (j < (int) version2.size()) {
                if (version2[j] == '.') {j++; break;}

                v2 += version2[j];
                j++;
            }

            x = stoi(v1); y = stoi(v2);

            if (x < y) return -1;
            else if (x > y) return 1;

            d++;
        }

        return 0;
    }
};