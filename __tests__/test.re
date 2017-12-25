let y = Raven.makeConfig(~level=`debug, ~tags=Js.Dict.fromList([("abce", "def")]), ());

Raven.config(~dsn="dns", ());