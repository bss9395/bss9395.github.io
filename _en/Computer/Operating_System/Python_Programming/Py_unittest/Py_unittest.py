''' Py_unittest.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: unittest
'''

from To_Test import *
import unittest


class Test(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print("=" * 10 + "setUpClass" + "=" * 10)
    @classmethod
    def tearDownClass(cls):
        print("=" * 10 + "tearDownClass" + "=" * 10)

    def setUp(self):
        print("=" * 10 + "setUp" + "=" * 10)

    def tearDown(self):
        print("=" * 10 + "tearDown" + "=" * 10)

    def test_Linear_Equation(self):
        self.assertEqual(_Linear_Equation(5, 9), -1.8)
        self.assertTrue(_Linear_Equation(4, 10) == -2.5)
        self.assertTrue(_Linear_Equation(4, -27) == 27 / 4)
        self.skipTest("skip temporarily")
        with self.assertRaises(ValueError):
            _Linear_Equation(0, 9)

    @unittest.skip("Skip Temporarily")
    def test_Quadratic_Equation(self):
        r1 = _Quadratic_Equation(1, -3, 2)
        self.assertCountEqual(r1, (1.0, 2.0))
        r1, r2 = _Quadratic_Equation(2, -7, 6)
        self.assertCountEqual((r1, r2), (1.5, 2.0))
        r = _Quadratic_Equation(1, -4, 4)
        self.assertEqual(r, 2.0)
        with self.assertRaises(ValueError):
            _Quadratic_Equation(0, 9, 3)


if __name__ == "__main__":
    unittest.main()
