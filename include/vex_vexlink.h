#ifndef VEX_VEXLINK_CLASS_H
#define VEX_VEXLINK_CLASS_H

#include "vex_device.h"

namespace vex {
	class vexlink : public device {
	  public:
		vexlink(int32_t index, const char* name, linkType type, bool isWired = false);
		~vexlink() override;

		bool installed() override;

		bool isLinked();

		bool isReceiving();

	  protected:
		vexlink(int32_t index);

		enum class tEventType {
			EVENT_DATA_RECEIVED = 0,
			EVENT_MSG_RECEIVED = 1
		};

		static const uint32_t max_buffer = 512;
		static const uint32_t max_name_len = 128;

		linkType _type;
		bool _isWired;

		uint8_t _txbuffer[max_buffer];
		uint8_t _rxbuffer[max_buffer];

		uint8_t _linkname[max_name_len];

		int32_t (*_avail)(uint32_t index);
		int32_t (*_peek)(uint32_t index);
		int32_t (*_read)(uint32_t index);
		int32_t (*_receive)(uint32_t index, uint8_t* buffer, int32_t length);

		int32_t (*_free)(uint32_t index);
		int32_t (*_write)(uint32_t index, uint8_t c);
		int32_t (*_transmit)(uint32_t index, uint8_t* buffer, int32_t length);

		int32_t debug(int32_t id);

		void baud(int32_t baudrate);

		static uint32_t _crc32_table[256];
		static uint32_t crc32(uint8_t* pData, uint32_t numberOfBytes, uint32_t accumulator);
		static uint32_t strcrc32(const char* str);
	};

	class serial_link : public vexlink {
	  public:
		serial_link(int32_t index, const char* name, linkType type, bool isWired = false);
		~serial_link() override;

		int32_t send(uint8_t* buffer, int32_t length);
		int32_t send(const char* buffer, int32_t length) { return send((uint8_t*)buffer, length); }

		int32_t receive(uint8_t* buffer, int32_t length, int32_t timeoutMs = 500);

		void received(void (*callback)(uint8_t*, int32_t));

	  private:
		static void _eventHandler(void* arg);
		void _eventHandler();

		void (*_callback)(uint8_t*, int32_t);
	};

	class message_link : public vexlink {
	  public:
		message_link(int32_t index, const char* name, linkType type, bool isWired = false);
		~message_link() override;

		int32_t send(const char* message);
		int32_t send(const char* message, double value);
		int32_t send(const char* message, int32_t index, double value);

		int32_t receive(char* message, int32_t length, int32_t timeoutMs = 500);

		void received(void (*callback)(const char*, const char*, double));
		void received(void (*callback)(const char*, const char*, int32_t, double));

		void received(const char* message, void (*callback)(const char*, const char*, double));
		void received(const char* message, void (*callback)(const char*, const char*, int32_t, double));

	  protected:
		class data {
		  public:
			const char* linkname;
			double value;
			int32_t index;
			uint32_t time;
			int32_t count;
		};

		void received(void (*callback)(const char*, data& data));

	  private:
		static void _eventHandler(void* arg);
		void _eventHandler();

		using tCallback_1 = void (*)(const char*, const char*, double);
		using tCallback_2 = void (*)(const char*, const char*, int32_t, double);
		using tCallback_3 = void (*)(const char*, data& data);

		const uint8_t id_dbl = 1;
		const uint8_t id_idx_dbl = 2;

		void* _callback;
		int32_t _callback_type;

		data _data;

		static const int32_t max_message_handlers = 512;

		struct _messageHandlers {
			uint32_t hash;
			void* callback;
			int32_t callback_type;
		} _messages[max_message_handlers];

		int32_t _message_index;

		void _addMessageHandler(const char* message, void* callback, int32_t type);
	};
}; // namespace vex

#endif
