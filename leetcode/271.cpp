#include <iostream>

using namespace std;

class Solution
{
  private:
    bool thousand;
    bool million;
    bool billion;

    string partToWords(int part)
    {
        string ret = "";
        string temp = "";
        int first = part / 100;
        part = part % 100;
        int middle = part / 10;
        int last = part % 10;
        if (first != 0)
        {
            ret += singleToWord(first) + " Hundred";
        }
        if (middle == 1)
        {
            temp=doubleToWords(middle, last);
            if(temp!=""){
                if(ret!="")
                    ret += " ";
                ret += temp;
            }
        }
        if(middle==0){
            temp=singleToWord(last);
            if(temp!=""){
                if(ret!="")
                    ret += " ";
                ret += temp;
            }
        }
        if (middle > 1)
        {
            temp=doubleToWords(middle, last);
            if(temp!=""){
                if(ret!="")
                    ret += " ";
                ret += temp;
            }
            string temp = singleToWord(last);
            if (temp != "")
            {
                ret += " " + temp;
            }
        }
        return ret;
    }

    string doubleToWords(int middle, int last)
    {
        if (middle == 1)
        {
            switch (last)
            {
            case 0:
                return "Ten";
            case 1:
                return "Eleven";
            case 2:
                return "Twelve";
            case 3:
                return "Thirteen";
            case 4:
                return "Fourteen";
            case 5:
                return "Fifteen";
            case 6:
                return "Sixteen";
            case 7:
                return "Seventeen";
            case 8:
                return "Eighteen";
            case 9:
                return "Nineteen";
            }
        }
        switch (middle)
        {
        case 2:
            return "Twenty";
        case 3:
            return "Thirty";
        case 4:
            return "Forty";
        case 5:
            return "Fifty";
        case 6:
            return "Sixty";
        case 7:
            return "Seventy";
        case 8:
            return "Eighty";
        case 9:
            return "Ninety";
        default:
            return "";
        }
    }
    string singleToWord(int single)
    {
        switch (single)
        {
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        default:
            return "";
        }
    }

  public:
    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }
        string ret = "";
        string temp = "";
        thousand = num / 1000 != 0 ? true : false;
        million = num / 1000000 != 0 ? true : false;
        billion = num / 1000000000 != 0 ? true : false;
        if (billion)
        {
            ret += partToWords(num / 1000000000) + " Billion";
            num = num % 1000000000;
        }
        if (million)
        {
            temp = partToWords(num / 1000000);
            if (temp != "")
            {
                if (ret != "")
                    ret += " ";
                ret += temp + " Million";
            }
            num = num % 1000000;
        }
        if (thousand)
        {
            temp = partToWords(num / 1000);
            if (temp != "")
            {
                if (ret != "")
                    ret += " ";
                ret += temp + " Thousand";
            }
            num = num % 1000;
        }
        temp = partToWords(num);
        if (temp != "")
        {
            if (ret != "")
                ret += " ";
            ret += temp;
        }
        return ret;
    }

    Solution()
    {
        thousand = false;
        million = false;
        billion = false;
    }
};

int main()
{
    int num;
    cin >> num;
    Solution solution;
    cout << "\"" + solution.numberToWords(num) + "\"" << endl;
    system("pause");
}