''' Number_To_RMB.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Number to RMB
'''

class RMB(object):
    _han = ['零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌', '玖']
    _integer_unit = ['', '拾', '佰', '仟', '万', '拾', '佰', '仟', '亿', '拾', '佰', '仟']
    _fraction_unit = ['角', '分']

    @staticmethod
    def _Number_To_RMB(number):
        integer = int(number)
        fraction = float(number) - integer
        (integer, fraction) = (f'{integer}', f'{int(fraction * 100 + 0.5):02}')
        print((integer, fraction))

        rmb = ''
        zero = 0
        leng = len(integer)
        for i in range(leng):
            inte = int(integer[i])
            if inte != 0:
                rmb += RMB._han[0] if 0 < zero else ''
                rmb += RMB._han[inte] + RMB._integer_unit[leng - 1 - i]
                zero = 0
            else:
                zero += 1
                if (leng - 1 - i) % 4 == 0 and zero < 4:
                    rmb += RMB._integer_unit[leng - 1 - i]

        rmb += '元'
        if int(fraction) == 0:
            rmb += '整'
            return rmb

        zero = 0
        leng = len(fraction)
        for i in range(leng):
            frac = int(fraction[i])
            if frac != 0:
                rmb += RMB._han[0] if 0 < zero else ''
                rmb += RMB._han[frac] + RMB._fraction_unit[i]
                zero = 0
            else:
                zero += 1
        return rmb


if __name__ == '__main__':
    number = 300000010.015
    print(number)
    print(RMB._Number_To_RMB(number))
