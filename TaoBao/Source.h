#ifndef SOURCE_H
#define SOURCE_H
#include "Taobao.h"
#include <cstdlib>

int cmp(const void* a, const void* b) {    // 结构体二级排序
    struct TaoBaoItem* c = (struct TaoBaoItem*)a;
    struct TaoBaoItem* d = (struct TaoBaoItem*)b;
    if (c->price != d->price)
        return d->price - c->price;
    else
        return d->volume_of_sales - c->volume_of_sales;
}
class SortByPrice : public SortInterface {
    public:
        void DoSort(TaoBaoItem item[], int size) {
            qsort(item, size, sizeof(item[0]), cmp);
        }
};
int compare2(const void* a, const void* b) {    // 结构体二级排序
    struct TaoBaoItem* c = (struct TaoBaoItem*)a;
    struct TaoBaoItem* d = (struct TaoBaoItem*)b;
    if (d->volume_of_sales != c->volume_of_sales)
        return d->volume_of_sales - c->volume_of_sales;
    else
        return d->price - c->price;
}
class SortBySales : public SortInterface {
    public:
        void DoSort(TaoBaoItem item[], int size) {
            qsort(item, size, sizeof(item[0]), compare2);
        }
};
class TaoBao {
    public:
        explicit TaoBao(SortInterface* strategy) : strategy_(strategy) {}
        void SetSortStrategy(SortInterface* strategy) {
            strategy_ = strategy;
        }
        // Use current strategy_ to do the sort.
        void sort(TaoBaoItem item[], int size) {
            strategy_->DoSort(item, size);
        }
    private:
        SortInterface *strategy_;
};

#endif

