class Solution:
    def intToRoman(self, num: int) -> str:
        thousands=["","M","MM","MMM"]
        hundreds=["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"]
        tens=["",'X','XX','XXX','XL','L','LX','LXX','LXXX','XC']
        ones=["","I","II","III","IV","V","VI","VII","VIII","IX"]
        t=thousands[num//1000]
        num=num%1000
        h=hundreds[num//100]
        num=num%100
        ten=tens[num//10]
        num=num%10
        o=ones[num%10]
        return t+h+ten+o
