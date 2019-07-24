#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class MedianFinder
{
private:
    vector<int> _minHeap;
    vector<int> _maxHeap;
    int _size;
    double _median;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        _size = 0;
        _median = 0;
        make_heap(_minHeap.begin(), _minHeap.end(), greater<int>());
        make_heap(_maxHeap.begin(), _maxHeap.end());
    }

    void addNum(int num)
    {
        if (_size == 0)
        {
            _minHeap.push_back(num);
            push_heap(_minHeap.begin(), _minHeap.end(), greater<int>());
            _median = num;
        }
        else
        {
            if (_size % 2 == 0)
            {
                if (num > _median)
                {
                    _minHeap.push_back(num);
                    push_heap(_minHeap.begin(), _minHeap.end(), greater<int>());
                    _median = _minHeap.front();
                }
                else
                {
                    _maxHeap.push_back(num);
                    push_heap(_maxHeap.begin(), _maxHeap.end());
                    _median = _maxHeap.front();
                }
            }
            else
            {
                if (num > _median)
                {
                    if (_minHeap.size()>_maxHeap.size())
                    {
                        pop_heap(_minHeap.begin(), _minHeap.end(), greater<int>());
                        _maxHeap.push_back(_minHeap.back());
                        _minHeap.pop_back();
                        push_heap(_maxHeap.begin(), _maxHeap.end());
                    }
                    _minHeap.push_back(num);
                    push_heap(_minHeap.begin(), _minHeap.end(), greater<int>());
                }
                else
                {
                    if (_maxHeap.size()>_minHeap.size())
                    {
                        pop_heap(_maxHeap.begin(), _maxHeap.end());
                        _minHeap.push_back(_maxHeap.back());
                        _maxHeap.pop_back();
                        push_heap(_minHeap.begin(), _minHeap.end(), greater<int>());
                    }
                    _maxHeap.push_back(num);
                    push_heap(_maxHeap.begin(), _maxHeap.end());
                }

                _median = (_minHeap.front() + _maxHeap.front()) / 2.0;
            }
        }
        _size++;
    }

    double findMedian()
    {
        return _median;
    }
};

int main()
{
    MedianFinder m;
    m.addNum(12);
    m.addNum(10);
    m.addNum(13);
    m.addNum(11);
    m.addNum(5);
    m.addNum(15);
    m.addNum(1);
    m.addNum(11);
    m.addNum(6);
    m.addNum(17);
    m.addNum(14);
    m.addNum(8);
    m.addNum(17);
    m.addNum(6);
    m.addNum(4);
    m.addNum(16);
    m.addNum(8);
    m.addNum(10);
    m.addNum(2);
    m.addNum(12);
    m.addNum(0);
    m.findMedian();
    system("pause");
    return 0;
}