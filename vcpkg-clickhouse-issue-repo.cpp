#include <iostream>
#include <clickhouse/client.h>

int main()
{
	clickhouse::ClientOptions options;
	options.SetHost( "127.0.0.1" );
	options.SetPort( 8123 );
	options.SetDefaultDatabase( "default" );
	options.SetUser( "default" );
	options.SetPassword( "default" );
	clickhouse::Client client( options );

	std::uint64_t value = 0;

	client.Select( "SELECT max(my_value) as max FROM users.user_data;",
				   [&value]( const clickhouse::Block& block )
	{


		value = block[ 0 ]->As<clickhouse::ColumnUInt64>()->At( 0 );
	}
	);
}
