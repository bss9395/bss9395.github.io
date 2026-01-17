/* Java_Flow.java
Author: BSS9395
Update: 2023-02-20T22:58:00+08@China-Shanghai+08
Design: Java Standard Library: Flow
*/

import java.util.concurrent.Flow;
import java.util.concurrent.SubmissionPublisher;

public class Java_Flow {
    static class Pick<T> implements Flow.Subscriber<T> {
        private Object _stub = null;
        private Flow.Subscription _subscription = null;
        public Pick(Object stub) {
            _stub = stub;
            System.out.printf("_stub.hashCode() == %s%n", _stub.hashCode());
        }

        @Override
        public void onSubscribe(Flow.Subscription subscription) {
            _subscription = subscription;
            _subscription.request(1);
        }

        @Override
        public void onNext(T item) {
            System.out.printf("%s%n", item);
            _subscription.request(1);
        }

        @Override
        public void onComplete() {
            System.out.printf("%s%n", "public void onComplete() {");
            synchronized (_stub) {
                _stub.notifyAll();
            }
        }

        @Override
        public void onError(Throwable throwable) {
            throwable.printStackTrace();
            synchronized (_stub) {
                _stub.notifyAll();
            }
        }
    }

    static public void main(String[] args)
        throws InterruptedException {
        _Post();
    }
    static public void _Post()
        throws InterruptedException {
        String stub = "stub";
        System.out.printf(" stub.hashCode() == %s%n", stub.hashCode());

        SubmissionPublisher<String> publisher = new SubmissionPublisher<String>();
        publisher.subscribe(new Pick<String>(stub));

        String[] array = new String[] {
            "C", "C++", "C#", "Java", "Python"
        };
        for(int i = 0; i < array.length; i += 1) {
            publisher.submit(array[i]);
        }
        publisher.close();

        synchronized (stub) {
            stub.wait();
        }
        System.out.println("At the end.");
    }
}
