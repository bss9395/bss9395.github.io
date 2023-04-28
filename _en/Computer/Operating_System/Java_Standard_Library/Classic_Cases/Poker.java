/* Poker.java
Author: BSS9395
Update: 2023-04-28T20:15:00+08@China-Guangdong-Zhanjiang+08
Design: Poker
*/

import java.util.*;

public class Poker {
	static public String[] _poker_types  = new String[] {
		"♦", "♣", "♥", "♠"
	};
	static public String[] _poker_values  = new String[] {
		"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
	};
	static public String[] _players_pool  = new String[] {
		"电脑玩家", "孙悟空", "猪八戒", "沙僧"
	};
	static public int      _players_count = _players_pool.length;

	LinkedList<String>          _cards_shuffle = new LinkedList<String>();
	public String[]             _players       = null;
	public LinkedList<String>[] _cards         = null;
	public Poker()	{
		System.out.println("Poker");

		for (int type = 0; type < _poker_types.length; type += 1) {
			for (int value = 0; value < _poker_values.length; value += 1)	{
				_cards_shuffle.add(_poker_types[type] + _poker_values[value]);
			}
		}
		Collections.shuffle(_cards_shuffle);

		_players = new String[_players_count];
		_cards   = new LinkedList[_players_count];
		for(int i = 0; i < _players_count; i += 1) {
			_players[i] = _players_pool[i];
			_cards[i]   = new LinkedList<String>();
		}
	}

	public void _Deliver_Cards() {
		System.out.println("_Deliver_Cards");

		ListIterator<String> iter = _cards_shuffle.listIterator();
		for(int index = 0; iter.hasNext() == true; ) {
			_cards[index].add(iter.next());
			index = (index + 1) % _cards.length;
		}
	}

	public void _Print_Cards(String player) {
		System.out.println("_Print_Cards");

		if(player == null) {
			for(int i = 0; i < _players_count; i += 1) {
				System.out.printf("[%s]", _players[i]);

				ListIterator<String> iter = _cards[i].listIterator();
				while(iter.hasNext() == true) {
					System.out.printf(" %s", iter.next());
				}
				System.out.println();
			}
		} else {
			int index = 0;
			for(; index < _players.length; index += 1) {
				if(_players[index].equals(player)) {
					break;
				}
			}
			if(0 <= index && index < _players.length) {
				System.out.printf("[%s]", player);
				ListIterator<String> iter = _cards[index].listIterator();
				while(iter.hasNext() == true) {
					System.out.printf(" %s", iter.next());
				}
				System.out.println();
			}
		}
	}

	public static void main(String[] args)	{
		Poker poker = new Poker();
		poker._Deliver_Cards();
		poker._Print_Cards(null);
		poker._Print_Cards("电脑玩家");
	}
}
