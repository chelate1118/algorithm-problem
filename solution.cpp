/**
 * 
 *  left side        right side
 *  
 *                   1. 1 4 1 2
 *  1                2.00000000
 *  1                1
 * ==============================
 *  24               1 00
 *   4                 96
 * ==============================
 *  281                 400
 *    1                 281
 * ==============================
 * 
 *             ......
 * 
 */

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Number
{
private:
    deque<int> data;

    void pick_up() {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] >= 10) {
                if (i+1 == data.size()) data.push_back(data[i] / 10);
                else data[i+1] += data[i] / 10;
                data[i] %= 10;
            }

            if (data[i] < 0) {
                data[i] += 10;
                data[i+1]--;
            }
        }

        for (int i = data.size()-1; i >= 0; i--) {
            if (data[i] == 0) data.pop_back();
            else break;
        }
    }

    Number(deque<int> _data) {
        data = _data;
    }

public:
    void print() {
        for (int i = data.size()-1; i>=0; i--) {
            cout << data[i];
        }
        cout << endl;
    }

    Number(int i) {
        data = deque<int>(1, i);
        pick_up();
    }

    void operator<<(int shift) {
        while (shift--) {
            data.push_front(0);
        }
    }

    Number operator*(int scalar) {
        Number ret(data);

        for (int& i: ret.data) {
            i *= scalar;
        }

        ret.pick_up();
        return ret;
    }

    Number operator+(Number num) {
        Number ret(data);

        int size = max(ret.data.size(), num.data.size());

        ret.data.resize(size);
        num.data.resize(size);

        for (int i = 0; i < size; i++) {
            ret.data[i] += num.data[i];
        }

        ret.pick_up();
        return ret;
    }

    Number operator-(Number num) {
        Number neg_num(num.data);

        for (int& i: neg_num.data) i *= -1;

        return *this + neg_num;
    }

    bool operator<(Number num) {
        if (data.size() != num.data.size()) {
            return data.size() < num.data.size();
        }

        for (int i = data.size()-1; i >= 0; i--) {
            if (data[i] == num.data[i]) continue;

            return data[i] < num.data[i];
        }

        return false;
    }
};

int n;
Number left_side(2), right_side(1);
vector<int> arr;

int main()
{
    cin >> n;
    
    int ans = 0;
    while (n--) {
        left_side << 1;
        right_side << 2;

        for (int i = 1; i <= 10; i++) {
            if (right_side < ((left_side + Number(i)) * i)) {
                i--;
                right_side = right_side - ((left_side + Number(i)) * i);
                left_side = left_side + (Number(i)*2);
                ans = i;
                break;
            }
        }
    }

    cout << ans;
}