#Задание 1
"""
def calculate_sum(formula, index):
    # Если достигнут конец строки
    if index + 1 == len(formula):
        # Получаем значение последней цифры и возвращаем его
        temp = int(formula[index])
        return temp
    else:
        # Получаем значение текущей цифры
        digit = int(formula[index])
        # Рекурсивно вызываем функцию для следующей цифры и добавляем текущее значение
        return digit + calculate_sum(formula, index + 2)

def main():
    # Запрос ввода формулы
    formula = input("Formula: ")
    # Проверка на четность длины строки и первый символ
    if len(formula) % 2 == 0 or formula[0] == '+':
        # Если формула некорректна, выводим сообщение
        print("Invalid formula!")
    else:
        # Иначе начинаем вычисления
        index = 0
        # Выводим результат вычислений
        print("Input:", calculate_sum(formula, index))

if __name__ == "__main__":
    main()
"""


#Задание 2

def get_permutation(n, k):
    result = ""  # Строка для хранения результирующей перестановки
    nums = list(range(1, n + 1))  # Список для хранения чисел от 1 до n

    factorial = [1] * n  # Список для хранения факториалов
    for i in range(1, n):
        factorial[i] = factorial[i - 1] * i  # Вычисляем факториалы для каждого числа от 1 до n

    k -= 1  # Уменьшаем k на 1, так как индексы начинаются с 0

    # Генерируем перестановку
    for i in range(n - 1, -1, -1):
        index = k // factorial[i]  # Определяем индекс текущего числа в nums
        k %= factorial[i]  # Обновляем значение k для следующего числа
        result += str(nums[index])  # Добавляем число в результирующую строку
        nums.pop(index)  # Удаляем выбранное число из списка

    return result  # Возвращаем результирующую перестановку

def main():
    n = 3  # Размер перестановки
    k = 3  # Номер перестановки
    permutation = get_permutation(n, k)  # Получаем перестановку
    print(permutation)  # Выводим перестановку

if __name__ == "__main__":
    main()
