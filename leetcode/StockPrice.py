class StockPrice(object):

    def __init__(self):
        self.latest_time = 0
        self.ts_to_price = dict()
        self.max_heap = [] # max price
        self.min_heap = [] # min price

    def update(self, timestamp, price):
        self.ts_to_price[timestamp] = price
        self.latest_time = max(self.latest_time, timestamp)
        heapq.heappush(self.max_heap, (-price, timestamp))
        heapq.heappush(self.min_heap, (price, timestamp))
        """
        :type timestamp: int
        :type price: int
        :rtype: None
        """

    def current(self) -> int:
        return self.ts_to_price[self.latest_time]
        """
        :rtype: int
        """
        

    def maximum(self)-> int:
        price, timestamp = self.max_heap[0]
        while -price != self.ts_to_price[timestamp]:
            heapq.heappop(self.max_heap)
            price, timestamp = self.max_heap[0]
        return -price
        """
        :rtype: int
        """

    def minimum(self)-> int:
        price, timestamp = self.min_heap[0]
        while price != self.ts_to_price[timestamp]:
            heapq.heappop(self.min_heap)
            price, timestamp = self.min_heap[0]
        return price
        """
        :rtype: int
        """
        


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()
