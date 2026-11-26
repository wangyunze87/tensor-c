#include <stdlib.h>
#include "tensor.h"

/*
 * 创建长度为 len 的张量。
 * 步骤：参数校验 -> 分配结构体 -> 分配数组（失败回滚）-> 置零 -> 记录长度。
 */
Tensor* tensor_create(int len)
{
    Tensor* t;
int i;
    /* TODO 1: 参数校验。len <= 0 时直接返回 NULL。 */
if(len<=0) return NULL;
    /* TODO 2: 分配 Tensor 结构体。malloc 返回 NULL 时直接返回 NULL。 */
t=malloc(sizeof(Tensor));
if(t==NULL){
    return NULL;
}
    /* TODO 3: 分配 data 数组（长度 len 个 float）。
       若这里分配失败，结构体 t 已经占了内存，必须先 free(t) 再返回 NULL，
       否则就是一处内存泄漏。 */
t->data = malloc(len * sizeof(float));
if(t->data==NULL){
    free(t);
    return NULL;
}
    /* TODO 4: 用循环把 data[0 .. len-1] 全部置 0.0f。 */
for(i=0;i<len;i++){
    t->data[i]=0.0f;
}
    t->len = len;
    return t;
}
void tensor_free(Tensor* t)
{
    /* TODO 1: 判空。t == NULL 直接 return。 */
if(t==NULL){
    return;
}
    /* TODO 2: 先释放 t->data，再释放 t 本身。 */
free(t->data);
free(t);
    /* 注意：free 之后不要再访问 t->len / t->data。 */
}
float tensor_get(const Tensor* t, int i)
{
    /* TODO 1: 边界判断。t 为 NULL，或 i < 0，或 i >= t->len，返回 0.0f。 */
if(t==NULL||i<0||i>=t->len)
return 0.0f;
else
return t->data[i];
    /* TODO 2: 合法时返回 t->data[i]。 */
}
int tensor_set(Tensor* t, int i, float value)
{
    /* TODO 1: 边界判断。t 为 NULL，或 i < 0，或 i >= t->len，返回 0。 */
if(t==NULL||i<0||i>=t->len)
return 0;
else
t->data[i] = value;
return 1;
    /* TODO 2: 合法时写入 t->data[i] = value，返回 1。 */
}
int tensor_len(const Tensor* t)
{
if(t==NULL)
return 0;
else
return t->len;

    /* TODO: t 为 NULL 返回 0；否则返回 t->len。 */
}
