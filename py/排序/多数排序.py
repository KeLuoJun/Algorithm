import os
import heapq
import random
from tqdm import tqdm

def merge_sort(data):
    """对列表执行归并排序"""
    if len(data) <= 1:
        return data

    mid = len(data) // 2
    left = merge_sort(data[:mid])
    right = merge_sort(data[mid:])
    return merge(left, right)


def merge(left, right):
    """合并两个已排序的列表"""
    sorted_list = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_list.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            j += 1

    # 添加剩余的元素
    sorted_list.extend(left[i:])
    sorted_list.extend(right[j:])

    return sorted_list


def external_merge_sort(input_file, output_file, chunk_size):
    # 第一步：将输入文件分块排序
    temps = []
    with open(input_file, 'r') as infile:
        while True:
            # 从文件中读取一块数据
            lines = infile.readlines(chunk_size)
            if not lines:
                break

            # 将每行数据转为整数（假设数据为整数）
            data = [int(line.strip()) for line in lines]

            # 使用归并排序对块进行排序
            sorted_data = merge_sort(data)

            # 将排序后的块写入临时文件
            temp_file = f"temp_{len(temps)}.txt"
            with open(temp_file, 'w') as chunk:
                chunk.write('\n'.join(map(str, sorted_data)))
            temps.append(temp_file)

    # 第二步：合并已排序的块
    with open(output_file, 'w') as outfile:
        heap = []
        temp_iters = []

        # 打开每个块文件，并初始化堆
        for temp_file in temps:
            f = open(temp_file, 'r')
            temp_iters.append(f)
            first_value = f.readline().strip()
            if first_value:
                heapq.heappush(heap, (int(first_value), len(temp_iters) - 1))

        # 执行多路归并
        while heap:
            smallest, idx = heapq.heappop(heap)
            outfile.write(f"{smallest}\n")

            next_value = temp_iters[idx].readline().strip()
            if next_value:
                heapq.heappush(heap, (int(next_value), idx))

        # 关闭所有块文件，并清理临时文件
        for f in temp_iters:
            f.close()
        for temp_file in temps:
            os.remove(temp_file)

def generate_input_file(path, n: int, m: int) -> None:
    """
    生成指定数量的随机数，并将它们写入到文件中

    :path : 文件路径
    :n : 随机数批次
    :m : 随机数批次大小
    """
    with open(path, 'w') as f:
        for _ in tqdm(range(n), desc="正在生成随机数"):
            data = [random.randint(0, 10000) for _ in range(m)]
            f.write('\n'.join(map(str, data)))
    f.close()


def main() -> None:
    input_file = 'input.txt'
    output_file = 'output.txt'
    generate_input_file(input_file, 1000, 10)
    
    external_merge_sort(input_file, output_file, 100)


if __name__ == '__main__':
    main()


