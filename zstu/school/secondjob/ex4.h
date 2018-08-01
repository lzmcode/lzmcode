class MyDate {
    private:
        int year, month, day;
    public:
        MyDate(int y, int m, int d);
        void calc(int &y, int &m, int &d);
        int queryYear() { return year; }
        int queryMonth() { return month; }
        int queryDay() { return day; }
};
