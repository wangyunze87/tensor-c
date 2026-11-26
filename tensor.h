#ifndef TENSOR_H
#define TENSOR_H

/*
 * 一维张量（float 向量）——本阶段最小封装。
 * 成员通过接口函数访问，外部代码不直接读写 data / len。
 */
typedef struct Tensor {
    float* data;   /* 元素数组，长度为 len */
    int    len;    /* 元素个数 */
} Tensor;

/*
 * 创建长度为 len 的张量，元素全部初始化为 0。
 * 返回值：成功返回有效指针；len <= 0 或内存不足返回 NULL。
 */
Tensor* tensor_create(int len);

/*
 * 释放张量占用的内存。
 * 传入 NULL 直接返回，不报错；释放后调用方不应再使用该指针。
 */
void tensor_free(Tensor* t);

/*
 * 读取第 i 个元素。
 * t 为 NULL 或 i 越界时返回 0。
 */
float tensor_get(const Tensor* t, int i);

/*
 * 写入第 i 个元素。
 * 成功返回 1；t 为 NULL 或 i 越界时不修改内容，返回 0。
 */
int tensor_set(Tensor* t, int i, float value);

/*
 * 返回元素个数；t 为 NULL 时返回 0。
 */
int tensor_len(const Tensor* t);

#endif /* TENSOR_H */
