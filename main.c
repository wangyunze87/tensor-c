#include <stdio.h>
#include "tensor.h"

int main(void)
{
    Tensor* t;
    int ret;

    /* 1. 创建长度 5 的张量；失败直接退出 */
    t = tensor_create(5);
    if (t == NULL) {
        printf("create failed\n");
        return 1;
    }

    /* 2. 核对长度，预期 5 */
    printf("len = %d (expect 5)\n", tensor_len(t));

    /* 3. 写入两个元素，预期都返回 1 */
    ret = tensor_set(t, 0, 3.14f);
    printf("set [0] ret = %d (expect 1)\n", ret);
    ret = tensor_set(t, 4, 2.71f);
    printf("set [4] ret = %d (expect 1)\n", ret);

    /* 4. 读回核对数值 */
    printf("get [0] = %.2f (expect 3.14)\n", tensor_get(t, 0));
    printf("get [4] = %.2f (expect 2.71)\n", tensor_get(t, 4));

    /* 5. 越界测试：set 下标 10 应被拒绝，get 下标 -1 应返回 0 */
    ret = tensor_set(t, 10, 1.0f);
    printf("set [10] ret = %d (expect 0)\n", ret);
    printf("get [-1] = %.2f (expect 0.00)\n", tensor_get(t, -1));

    /* 6. 释放张量 */
    tensor_free(t);

    return 0;
}
