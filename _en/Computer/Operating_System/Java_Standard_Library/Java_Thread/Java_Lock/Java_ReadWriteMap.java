/* ReadWriteMap.java
Author: BSS9395
Update: 2023-02-24T21:44:00+08@China-Shanghai+08
Design: ReadWriteMap
*/

import java.util.Map;
import java.util.TreeMap;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class ReadWriteMap<Key_, Value_> {
    private final Map<Key_, Value_> _map       = new TreeMap<Key_, Value_>();
    private final ReentrantReadWriteLock _lock = new ReentrantReadWriteLock();
    private final Lock _read_lock              = _lock.readLock();
    private final Lock _write_lock             = _lock.writeLock();

    public Value_ _Get(Key_ key) {
        _read_lock.lock();
        try {
            return _map.get(key);
        } finally {
            _read_lock.unlock();
        }
    }

    public Key_[] _Keys() {
        _read_lock.lock();
        try {
            return (Key_[]) _map.keySet().toArray();
        } finally {
            _read_lock.unlock();
        }
    }

    public Value_ _Put(Key_ key, Value_ value) {
        _write_lock.lock();
        try {
            return _map.put(key, value);
        } finally {
            _write_lock.unlock();
        }
    }

    public void _Clear() {
        _write_lock.lock();
        try {
            _map.clear();
        } finally {
            _write_lock.unlock();
        }
    }
}

