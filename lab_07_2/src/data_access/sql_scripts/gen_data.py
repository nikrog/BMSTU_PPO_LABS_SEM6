from faker import Faker
from random import randint, random
from random import choice, uniform

from mimesis import Datetime

MAX_N = 1000

datetime = Datetime()
banks = [1, 2, 6, 7, 8]


def generate_products():
    faker = Faker()
    f = open('products.csv', 'w')
    co_set = set()
    cap_set = set()

    for i in range(MAX_N):
        ptype = randint(0, 1)
        name = faker.name()
        while name in co_set:
            name = faker.name()
        bank_id = choice(banks)
        rate = uniform(-99.99, 99.99)
        min_time = randint(1, 10000)
        max_time = randint(1, 10000)
        min_sum = uniform(1, 10000000)
        max_sum = min_sum + uniform(1000, 10000000)
        currency = randint(0, 3)
        sum_rating = randint(1, 100)
        count_rating = randint(1, sum_rating)
        line = "{0};{1};{2};{3};{4};{5};{6};{7};{8};{9};{10}\n".format(
            ptype,
            name,
            bank_id,
            rate,
            min_time,
            max_time,
            min_sum,
            max_sum,
            currency,
            sum_rating,
            count_rating)
        f.write(line)
    f.close()

generate_products()